/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:00:11 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:30:15 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_color(t_fdf *fdf)
{
	fdf->color = (int *)malloc(sizeof(int) * 7);
	fdf->color[0] = 0xFF0000;
	fdf->color[1] = 0xFFA200;
	fdf->color[2] = 0xFFFB00;
	fdf->color[3] = 0x0FFF00;
	fdf->color[4] = 0x00FFF7;
	fdf->color[5] = 0x0055FF;
	fdf->color[6] = 0xFF00EC;
}

void	color_grid(t_fdf *fdf)
{
	int		i;
	int		j;
	int		c;

	j = 0;
	c = rand() % 7;
	while (j < fdf->size_y)
	{
		i = 0;
		while (i < fdf->size_x)
		{
			if (!fdf->coord[j][i].z)
				fdf->coord[j][i].color = fdf->color[c];
			i++;
		}
		j++;
	}
}

void	color_height(t_fdf *fdf)
{
	int		i;
	int		j;
	int		c;

	j = 0;
	c = rand() % 7;
	while (j < fdf->size_y)
	{
		i = 0;
		while (i < fdf->size_x)
		{
			if (fdf->coord[j][i].z)
				fdf->coord[j][i].color = fdf->color[c];
			i++;
		}
		j++;
	}
}

int		ident_color(t_fdf *fdf, int j, int i, int id)
{
	if (id)
	{
		if (fdf->coord[i][j + 1].z)
			return (fdf->coord[i][j + 1].color);
		if (fdf->coord[i][j].z)
			return (fdf->coord[i][j].color);
	}
	if (!id)
	{
		if (fdf->coord[i + 1][j].z)
			return (fdf->coord[i + 1][j].color);
		if (fdf->coord[i][j].z)
			return (fdf->coord[i][j].color);
	}
	return (fdf->coord[i][j].color);
}
