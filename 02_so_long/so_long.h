#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_map
{
	char			*line;
	struct s_map	*next;
}t_map;

typedef struct	s_param
{
	t_map	*map;
	int		fd;
}t_param;


