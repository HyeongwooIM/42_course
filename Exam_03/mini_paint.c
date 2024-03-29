#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct	s_zone
{
	int		w;
	int		h;
	char	c;
}				t_zone;

typedef struct	s_form
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	c;
}				t_form;

void	o_browse_tab(char tab[300][300], t_zone *zone, void(*fct)(int, int, char [300][300], void *), void *arg)
{
	int		x;
	int		y;

	y = -1;
	while (++y < zone->h)
	{
		x = -1;
		while (++x < zone->w)
			fct(y, x, tab, arg);
	}
}

void	o_print(int y, int x, char tab[300][300], void *arg)
{
	t_zone	*zone;

	zone = (t_zone *)arg;
	write(1, &tab[y][x], 1);
	if (x == zone->w - 1)
		write(1, "\n", 1);
}

int	o_putstr_error(const char *str, int rv)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (rv);
}

void	o_set_tab(int y, int x, char tab[300][300], void *arg)
{
	t_zone	*zone;

	zone = (t_zone *)arg;
	tab[y][x] = zone->c;
}

void	o_draw_form(int y, int x, char tab[300][300], void *arg)
{
	t_form	*form;
	float	dist;

	form = (t_form *)arg;
	dist = sqrt((x - form->x) * (x - form->x) + (y - form->y) * (y - form->y));
	if (dist <= form->r)
	{
		if (dist <= form->r && dist > form->r - 1)
			tab[y][x] = form->c;
		else if (form->type == 'C')
			tab[y][x] = form->c;
	}
}

int	o_form(char tab[300][300], t_zone *zone, FILE *file)
{
	int		rv;
	t_form	form;

	while ((rv = fscanf(file, "%c %f %f %f %c\n", &form.type, &form.x, &form.y, &form.r, &form.c)) == 5)
	{
		if (form.r <= 0 || (form.type != 'C' && form.type != 'c'))
			return (1);
		o_browse_tab(tab, zone, o_draw_form, &form);
	}
	if (rv != -1 && rv)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_zone	zone;
	FILE	*file;
	char	tab[300][300];

	if (argc != 2)
		return (o_putstr_error("Error: argument\n", 1));
	file = fopen(argv[1], "r");
	if (!file)
		return (o_putstr_error("Error: Operation file corrupted\n", 1));
	if (fscanf(file, "%d %d %c\n", &zone.w, &zone.h, &zone.c) != 3 || zone.w <= 0 || zone.h <= 0 || zone.w > 300 || zone.h > 300)
		return (o_putstr_error("Error: Operation file corrupted\n", 1));
	o_browse_tab(tab, &zone, o_set_tab, &zone);
	if (o_form(tab, &zone, file))
		return (o_putstr_error("Error: Operation file corrupted\n", 1));
	fclose(file);
	o_browse_tab(tab, &zone, o_print, &zone);
	return (0);
}