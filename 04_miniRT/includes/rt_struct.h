/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:33:47 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/23 16:20:01 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

# include <stdio.h>
# include <math.h>

typedef struct s_vector			t_vector;
typedef struct s_vector			t_color_v;
typedef struct s_vector			t_coord_v;

typedef struct s_ambient		t_ambient;
typedef struct s_camera			t_camera;
typedef struct s_light			t_light;
typedef struct s_sphere			t_sphere;
typedef struct s_sphere_info	t_sphere_info;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;
typedef struct s_cylinder_info	t_cylinder_info;
typedef struct s_hit_record		t_hit_record;
typedef struct s_ray			t_ray;
typedef struct s_scene			t_scene;
typedef struct s_my_list		t_objects;
typedef struct s_object			t_object;
typedef struct s_mlx			t_mlx;
typedef struct s_node			t_node;
typedef struct s_my_list		t_my_list;

typedef int						t_object_type;
typedef int						t_bool;

# define EPSILON 0.000001
# define WIDTH	800
# define HEIGHT	500
# define FALSE 0
# define TRUE 1

enum	e_keycode
{
	KEY_ESC = 53,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_COMMA = 43,
	KEY_DOT = 47,
	ARROW_U = 126,
	ARROW_D = 125,
	ARROW_L = 123,
	ARROW_R = 124
};

enum	e_data_type
{
	ERROR = -1,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	COMMENT
};

struct	s_vector
{
	double	x;
	double	y;
	double	z;
};

struct s_node
{
	void		*content;
	int			data_type;
	t_color_v	color;
	t_node		*prev;
	t_node		*next;
};

struct s_my_list
{
	int		len;
	t_node	*head;
	t_node	*tail;
};

struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct	s_ambient
{
	double		ratio;
	t_color_v	rgb;
};

struct	s_camera
{
	t_coord_v	coord;
	t_vector	dir;
	double		fov;
	t_vector	right_normal;
	t_vector	up_normal;
	t_coord_v	left_bottom;
	double		focal_len;
};

struct	s_light
{
	t_coord_v	coord;
	double		ratio;
	t_color_v	color;
};

struct	s_sphere
{
	t_coord_v	coord;
	double		diameter;
	t_color_v	rgb;
};

struct	s_sphere_info
{
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	t_sphere	*sp;
	t_vector	oc;
	t_vector	normal;
};

struct	s_plane
{
	t_coord_v	coord;
	t_vector	vector;
	t_color_v	rgb;
};

struct	s_cylinder
{
	t_coord_v	coord;
	t_vector	vector;
	double		diameter;
	double		height;
	t_color_v	rgb;
};

struct	s_cylinder_info
{
	t_cylinder		*cy;
	t_vector		u;
	t_vector		o;
	t_vector		delta_p;
	double			r;
	double			a;
	double			half_b;
	double			c;
	double			discriminant;
	double			sqrtd;
	double			root;
	double			hit_height;
};

struct	s_ray
{
	t_coord_v		origin;
	t_vector		dir;
};

struct	s_hit_record
{
	double			tmin;
	double			tmax;
	t_vector		normal;
	t_color_v		albedo;
	double			t;
	t_coord_v		point;
};

struct s_scene
{
	t_ambient			ambient;
	t_camera			camera;
	t_light				light;
	t_objects			*objects;
	t_vector			dup_check;
	t_ray				ray;
	t_hit_record		rec;
	t_mlx				*mlx;
};

#endif
