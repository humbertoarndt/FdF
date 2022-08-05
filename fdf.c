/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:34:48 by harndt            #+#    #+#             */
/*   Updated: 2022/08/05 02:21:24 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	expose_hook(t_win *data)
{
	render_background(&data->img, C_NIER_BG);
	rotate(&data->fdf);
	projection(&data->fdf);
	plot_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
							0, 0);
	draw_legend(data);
	return (1);
}

void	print_points(t_fdf *fdf)
{
	int	i;
	int	x;

	i = 0;
	while (fdf->points[i])
	{
		x = 0;
		while (fdf->points[i][x])
		{
			ft_printf("%d ", fdf->points[i][x]->pz);
			x++;
		}
		i++;
		ft_printf("\n");
	}
}

int	main(int argc, char **argv)
{
	char	path[5000];
	t_win	*data;
	char	*file_name;

	if (argc != 2)
		print_error(USG_ERROR);
	data = (t_win *)malloc(sizeof (t_win));
	file_name = argv[1];
	ft_strlcpy(path, "./test_maps/", 13);
	ft_strlcat(path, file_name, 100);
	init_mlx(data, path);
	read_input(&data->fdf, path);
	mlx_expose_hook(data->win_ptr, expose_hook, data);
	mlx_key_hook(data->win_ptr, press_key, data);
	mlx_mouse_hook(data->win_ptr, press_mouse, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, close_app, data);
	mlx_loop(data->mlx_ptr);
	end_program(data);
	return (0);
}
