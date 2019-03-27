/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:03:49 by akoropet          #+#    #+#             */
/*   Updated: 2019/03/27 20:21:40 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_scale(int key, t_fdf *fdf)
{
	if (key == 124 && fdf->coord[fdf->size_y - 1][fdf->size_y - 1].x < 2000)
		fdf->step.x += 10;
	if (key == 123 && fdf->coord[0][0].x > -2000)
		fdf->step.x -= 10;
	if (key == 126 && fdf->coord[0][0].y > -2000)
		fdf->step.y -= 10;
	if (key == 125 && fdf->coord[fdf->size_y - 1][fdf->size_y - 1].y < 2000)
		fdf->step.y += 10;
	if (key == 69 && fdf->scale < 50)
	{
		fdf->scale_z += (fdf->scale_z / fdf->scale);
		fdf->scale += 1;
	}
	if (key == 78 && fdf->scale > 1)
	{
		fdf->scale_z -= (fdf->scale_z / fdf->scale);
		fdf->scale -= 1;
	}
	if (key == 116 && fdf->scale_z < 50)
		fdf->scale_z += 1;
	if (key == 121 && fdf->scale_z > -50)
		fdf->scale_z -= 1;
}

void	key_color(int key, t_fdf *fdf)
{
	if (key == 83)
		color_grid(fdf);
	if (key == 84)
		color_height(fdf);
	if (key == 85)
	{
		color_grid(fdf);
		color_height(fdf);
	}
}

int		key(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	if (key == 18)
	{
		fdf->iso = 0;
		fdf->persp = 0;
	}
	if (key == 19)
	{
		fdf->iso = 1;
		fdf->persp = 0;
	}
	if (key == 20)
	{
		fdf->iso = 0;
		fdf->persp = 1;
	}
	key_color(key, fdf);
	key_scale(key, fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_X, WIN_Y);
	recreate_map(fdf);
	image(fdf);
	return (0);
}

int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
