/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:01:23 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:30:33 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	scale(t_fdf *fdf)
{
	int		i;
	int		j;
	float	dx;
	float	dy;

	j = 0;
	dx = find_center(fdf, 'x');
	dy = find_center(fdf, 'y');
	while (j < fdf->size_y)
	{
		i = 0;
		while (i < fdf->size_x)
		{
			fdf->coord[j][i].x *= (fdf->scale);
			fdf->coord[j][i].y *= (fdf->scale);
			fdf->coord[j][i].z *= fdf->scale_z;
			i++;
		}
		j++;
	}
}

void	center(t_fdf *fdf)
{
	float	dx;
	float	dy;

	dx = find_center(fdf, 'x');
	dy = find_center(fdf, 'y');
	fdf->start_point.x = (WIN_X / 2) - dx + fdf->step.x;
	fdf->start_point.y = (WIN_Y / 2) - dy + fdf->step.y;
}

void	move(t_fdf *fdf)
{
	int		i;
	int		j;

	j = 0;
	while ((fdf->step.x || fdf->step.y) && j < fdf->size_y)
	{
		i = 0;
		while (i < fdf->size_x)
		{
			fdf->coord[j][i].x += fdf->step.x;
			fdf->coord[j][i].y += fdf->step.y;
			i++;
		}
		j++;
	}
}

float	find_center(t_fdf *fdf, char axis)
{
	int		i;
	int		j;
	float	min;
	float	max;

	j = 0;
	min = axis == 'x' ? fdf->coord[0][0].x : fdf->coord[0][0].y;
	max = axis == 'x' ? fdf->coord[0][0].x : fdf->coord[0][0].y;
	while (j < fdf->size_y)
	{
		i = -1;
		while (++i < fdf->size_x)
		{
			min = axis == 'x' && fdf->coord[j][i].x < min && !fdf->coord[j][i].z
				? fdf->coord[j][i].x : min;
			max = axis == 'x' && fdf->coord[j][i].x > max && !fdf->coord[j][i].z
				? fdf->coord[j][i].x : max;
			min = axis == 'y' && fdf->coord[j][i].y < min && !fdf->coord[j][i].z
				? fdf->coord[j][i].y : min;
			max = axis == 'y' && fdf->coord[j][i].y > max && !fdf->coord[j][i].z
				? fdf->coord[j][i].y : max;
		}
		j++;
	}
	return ((max + min) / 2);
}
