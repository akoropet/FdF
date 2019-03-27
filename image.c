/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:55:49 by akoropet          #+#    #+#             */
/*   Updated: 2019/03/27 18:30:55 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perspectiv(t_fdf *fdf)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	z;

	j = 0;
	while (j < fdf->size_y)
	{
		i = 0;
		while (i < fdf->size_x)
		{
			x = fdf->coord[j][i].x;
			y = fdf->coord[j][i].y;
			z = -(fdf->coord[j][i].z / 1000);
			fdf->coord[j][i].x = (x / (z + 1));
			fdf->coord[j][i].y = (y / (z + 1));
			fdf->coord[j][i].z = (1 / (z + 1));
			i++;
		}
		j++;
	}
}

void	image(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	scale(fdf);
	move(fdf);
	fdf->iso ? isometric(fdf) : 0;
	fdf->persp ? perspectiv(fdf) : 0;
	center(fdf);
	while (i < fdf->size_y)
	{
		j = 0;
		while (j < fdf->size_x)
		{
			if (j + 1 < fdf->size_x)
				ft_dda(fdf, fdf->coord[i][j], fdf->coord[i][j + 1],
					ident_color(fdf, j, i, 1));
			if (i + 1 < fdf->size_y)
				ft_dda(fdf, fdf->coord[i][j], fdf->coord[i + 1][j],
					ident_color(fdf, j, i, 0));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void	isometric(t_fdf *fdf)
{
	int		i;
	int		j;
	float	x;
	float	y;

	j = 0;
	while (j < fdf->size_y)
	{
		i = 0;
		while (i < fdf->size_x)
		{
			x = fdf->coord[j][i].x;
			y = fdf->coord[j][i].y;
			fdf->coord[j][i].x = (x + y) * cos(0.5);
			fdf->coord[j][i].y = (x - y) * -sin(0.5) - fdf->coord[j][i].z / 10;
			i++;
		}
		j++;
	}
}

void	ft_dda(t_fdf *fdf, t_coord p1, t_coord p2, int color)
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	int		length;

	dx = (p2.x - p1.x);
	dy = (p2.y - p1.y);
	length = fabsf(dx) > fabsf(dy) ? fabsf(dx) + 1 : fabsf(dy) + 1;
	dx /= length;
	dy /= length;
	x = (float)p1.x + (fdf->start_point.x);
	y = (float)p1.y + (fdf->start_point.y);
	while (length--)
	{
		if ((x < WIN_X && y < WIN_Y) && (x >= 0 && y >= 0))
		{
			if (p1.z != 0 || p2.z != 0)
				put_pixel_image(fdf, x, y, color);
			else
				put_pixel_image(fdf, x, y, color);
		}
		x += dx;
		y += dy;
	}
}
