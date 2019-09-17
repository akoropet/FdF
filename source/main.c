/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:13:07 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:30:27 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	reset(t_fdf *fdf)
{
	fdf->map = NULL;
	fdf->size_x = 0;
	fdf->size_y = 0;
	fdf->coord = NULL;
	fdf->start_point.x = 0;
	fdf->start_point.y = 0;
	fdf->rotate = 0;
	fdf->step.x = 0;
	fdf->step.y = 0;
	fdf->elastic.x = 0;
	fdf->elastic.y = 0;
	fdf->def_color = 0xFFFFFF;
	fdf->iso = 0;
	fdf->persp = 0;
}

void	put_pixel_image(t_fdf *fdf, int x, int y, int color)
{
	int				bpp;
	int				sl;
	int				e;
	char			*res;
	unsigned int	rgb;

	res = mlx_get_data_addr(fdf->img_ptr, &bpp, &sl, &e);
	rgb = mlx_get_color_value(fdf->mlx_ptr, color);
	ft_memcpy((void *)(res + y * sl + x * bpp / 8), (void *)&rgb, 4);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	reset(fdf);
	if (ac == 2 && parcer(fdf, av[1]))
	{
		ft_color(fdf);
		create_map(fdf);
		fdf->scale = 1;
		fdf->scale_z = fdf->scale;
		fdf->mlx_ptr = NULL;
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_X, WIN_Y, av[1]);
		fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_X, WIN_Y);
		image(fdf);
		mlx_hook(fdf->win_ptr, 2, 5, key, fdf);
		mlx_hook(fdf->win_ptr, 17, 0, close_win, NULL);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_putstr("Invalid map data\n");
	return (0);
}
