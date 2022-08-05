/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:42:49 by harndt            #+#    #+#             */
/*   Updated: 2022/08/05 01:58:11 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*init_fdf(char *path)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		print_error(MLC_ERROR);
	fdf->points = NULL;
	fdf->controls = init_controls();
	fdf->height = get_height(path);
	fdf->width = get_width(path);
	fdf->delta_x = 0;
	fdf->delta_y = 0;
	fdf->slope_x = 0;
	fdf->slope_y = 0;
	fdf->x = 0;
	fdf->y = 0;
	fdf->err = 0;
	fdf->projection = ISO;
	return (fdf);
}

void	init_mlx(t_win	*data, char *path)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		print_error(MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, W_NAME);
	if (data->win_ptr == NULL)
	{
		free (data->win_ptr);
		print_error(WIN_ERROR);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
										&data->img.line_len, &data->img.endian);
	data->fdf = *init_fdf(path);
}

t_ctrls	*init_controls(void)
{
	t_ctrls	*new_controls;

	new_controls = (t_ctrls *)malloc(sizeof(t_ctrls));
	if (!new_controls)
		print_error(MLC_ERROR);
	new_controls->zoom = 25;
	new_controls->zmod = 10;
	new_controls->shift_x = W_WIDTH / 2;
	new_controls->shift_y = W_HEIGHT / 2;
	new_controls->x_angle = 0;
	new_controls->y_angle = 0;
	new_controls->z_angle = 0;
	new_controls->color = 0;
	return (new_controls);
}

void	reset_controls(t_fdf *fdf)
{
	fdf->controls->shift_x = W_WIDTH / 2;
	fdf->controls->shift_y = W_HEIGHT / 2;
	fdf->controls->zoom = 25;
	fdf->controls->zmod = 10;
	fdf->controls->color = 0;
	fdf->controls->y_angle = 0;
	fdf->controls->x_angle = 0;
	fdf->controls->z_angle = 0;
}

void	check_fdf(t_fdf *fdf)
{
	ft_printf("height:\t\t|%d|\n", fdf->height);
	ft_printf("width:\t\t|%d|\n", fdf->width);
	ft_printf("delta_x:\t|%d|\n", fdf->delta_x);
	ft_printf("delta_y:\t|%d|\n", fdf->delta_y);
	ft_printf("slope_x:\t|%d|\n", fdf->slope_x);
	ft_printf("slope_y:\t|%d|\n", fdf->slope_y);
	ft_printf("x:\t\t|%d|\n", fdf->x);
	ft_printf("y:\t\t|%d|\n", fdf->y);
	ft_printf("err:\t\t|%d|\n\n", fdf->err);
}
