#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct s_zone
{
	int	w;
	int h;
	char c;
} t_zone;

typedef struct s_form
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	c;
}t_form;

int main(int ac, char **av)
{
	
	t_zone	zone;
	t_form	form;
	FILE	*file;
	char	map[300][300];
	int		dist;
	int	rv;


	if (ac != 2)
		return (1);
	file = fopen(av[1], "r");
	if (!file)
		return (1);
		
	if (fscanf(file, "%d %d %c\n", &zone.w, &zone.h, &zone.c) != 3 || zone.w <= 0 || zone.h <= 0 || zone.w > 300 || zone.h > 300)
		return (1);
	write(1, "123", 3);
	int i = -1;
	int j = -1;
	while (++i < zone.w)
	{
		j = -1;
		while (++j < zone.h)
			map[i][j] = zone.c;
	}
	while ((rv = fscanf(file, "%c %f %f %f %c\n", &form.type, &form.x, &form.y, &form.r, &form.c)) == 5)
	{
		i = -1;
		while (++i < zone.h)
		{
			j = -1;
			while (++j < zone.w)
			{
				dist = sqrt((form.x - i) * ( form.x - i) + (form.y - j) * (form.y - j));
				if (dist <= form.r)
				{
					if (dist <= form.r && dist > form.r - 1)
						map[i][j] = form.c;
					else if(form.type == 'C')
						map[i][j] = form.c;
				}
			}
		}
	}
	if (rv != -1 && rv)
		return (1);
	fclose(file);
	i = -1;
	while (++i < zone.h)
	{
		j = -1;
		while (++j < zone.w)
		{
			write(1, &map[i][j], 1);
		}
		write(1, "\n", 1);
	}
	return (0);
}