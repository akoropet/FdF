/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:06:15 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:29:11 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define WIN_X 1000
# define WIN_Y 1000

typedef struct		s_coord
{
	float				x;
	float				y;
	float				z;
	int					color;
}					t_coord;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				size_x;
	int				size_y;
	float			scale;
	float			scale_z;
	float			rotate;
	t_coord			elastic;
	t_coord			step;
	t_coord			**coord;
	t_coord			start_point;
	char			*map;
	int				*color;
	int				def_color;
	int				iso;
	int				persp;
}					t_fdf;

int					parcer(t_fdf *fdf, char *file);
int					valid_line(t_fdf *fdf, char *str, int count);
int					valid_color(char *str, int *i);
char				*join_to_buf(char *buf, char *str);

void				color(t_fdf *fdf, int j, int i, char *str);
void				add_coord(t_fdf *fdf, char **str, int i, int j);
void				reset_coord(t_fdf *fdf, int i, int j);
void				recreate_map(t_fdf *fdf);
void				create_map(t_fdf *fdf);

void				ft_dda(t_fdf *fdf, t_coord p1, t_coord p2, int color);
void				isometric(t_fdf *fdf);
void				image(t_fdf *fdf);
void				perspectiv(t_fdf *fdf);

void				ft_color(t_fdf *fdf);
void				color_grid(t_fdf *fdf);
void				color_height(t_fdf *fdf);
int					ident_color(t_fdf *fdf, int j, int i, int id);

void				scale(t_fdf *fdf);
void				center(t_fdf *fdf);
void				move(t_fdf *fdf);
float				find_center(t_fdf *fdf, char axis);

int					key(int key, t_fdf *fdf);
void				key_color(int key, t_fdf *fdf);
void				key_scale(int key, t_fdf *fdf);

void				reset(t_fdf *fdf);
int					close_win(void *param);
void				put_pixel_image(t_fdf *fdf, int x, int y, int color);

#endif
