/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:32:06 by harndt            #+#    #+#             */
/*   Updated: 2022/08/04 20:17:12 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Set the zoom object
 * 
 * @param button The button pressed.
 * @param data The data object.
 */
static void	set_zoom(int button, t_win *data)
{
	if (button == 4)
		data->fdf.controls->zoom += 1;
	if (button == 5)
		data->fdf.controls->zoom -= 1;
	if (data->fdf.controls->zoom < 1)
		data->fdf.controls->zoom = 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	expose_hook(data);
}

/**
 * @brief Set the position object
 * 
 * @param x The position on the x axys.
 * @param y The position on the y axys.
 * @param data The data object.
 * @return int 1
 */
static int	set_position(int x, int y, t_win *data)
{
	data->fdf.controls->shift_x = x;
	data->fdf.controls->shift_y = y;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	expose_hook(data);
	return (1);
}

int	press_mouse(int button, int x, int y, t_win *data)
{
	if (button == 4 || button == 5)
		set_zoom(button, data);
	else if (button == 1)
		set_position(x, y, data);
	return (1);
}
