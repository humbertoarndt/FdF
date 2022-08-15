/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:38:22 by harndt            #+#    #+#             */
/*   Updated: 2022/08/15 22:12:52 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Set the altitude object
 * 
 * @param keysym The keysym pressed on the keyboard.
 * @param data The data object.
 */
static void	set_altitude(int keysym, t_win *data)
{
	if (keysym == 97)
		data->fdf->controls->zmod -= 1;
	else if (keysym == 115)
		data->fdf->controls->zmod += 1;
	if (data->fdf->controls->zmod < 1)
		data->fdf->controls->zmod = 1;
	else if (data->fdf->controls->zmod > 100)
		data->fdf->controls->zmod = 100;
	reproject(data);
}

/**
 * @brief Set the projections object
 * 
 * @param keysym The keysym pressed on the keyboard.
 * @param data The data object.
 */
static void	set_projections(int keysym, t_win *data)
{
	if (keysym == 49)
		data->fdf->projection = ISO;
	else if (keysym == 50)
		data->fdf->projection = DIMETRIC;
	else if (keysym == 51)
		data->fdf->projection = CONIC;
	reproject(data);
}

/**
 * @brief Set the color mode object
 * 
 * @param data The data object.
 */
static void	set_color_mode(t_win *data)
{
	data->fdf->controls->color = (!data->fdf->controls->color);
	reproject(data);
}

/**
 * @brief Set the angle object
 * 
 * @param keysym The keysym pressed on the keyboard.
 * @param data The data object.
 */
static void	set_angle(int keysym, t_win *data)
{
	if (keysym == KEY_LEFT)
		data->fdf->controls->y_angle -= 5;
	else if (keysym == KEY_RIGHT)
		data->fdf->controls->y_angle += 5;
	else if (keysym == KEY_UP)
		data->fdf->controls->x_angle -= 5;
	else if (keysym == KEY_DOWN)
		data->fdf->controls->x_angle += 5;
	reproject(data);
}

int	press_key(int keysym, t_win *data)
{
	if (keysym == KEY_ESC)
		end_program(data);
	else if (keysym >= NUMKEY_1 && keysym <= NUMKEY_4)
		set_projections(keysym, data);
	else if (keysym == KEY_A || keysym == KEY_S)
		set_altitude(keysym, data);
	else if (keysym == KEY_C)
		set_color_mode(data);
	else if (keysym >= KEY_LEFT && keysym <= KEY_DOWN)
		set_angle(keysym, data);
	else if (keysym == KEY_D)
	{
		reset_controls(data->fdf);
		reproject(data);
	}
	return (1);
}
