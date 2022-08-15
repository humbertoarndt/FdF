/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:40:04 by harndt            #+#    #+#             */
/*   Updated: 2022/08/11 01:50:06 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Increases x in each iteratin, Y only gets increased if decision
 * variable (ERR) is greater than zero. In that case ERR gets readjusted.
 * 
 * @param data The struct where data is stored.
 * @param start Starting point.
 * @param end Ending point.
 */
static void	plot_low(t_win *data, t_points *start, t_points *end)
{
	int	i;

	i = 0;
	while (i++ <= data->fdf->delta_x)
	{
		img_pix_put(&data->img, data->fdf->x, data->fdf->y, \
					get_color(data->fdf, start, end));
		if (data->fdf->err > 0)
		{
			data->fdf->y += data->fdf->slope_y;
			data->fdf->err = data->fdf->err + 2 * (data->fdf->delta_y - \
							data->fdf->delta_x);
		}
		else
			data->fdf->err = data->fdf->err + 2 * data->fdf->delta_y;
		data->fdf->x += data->fdf->slope_x;
	}
}

/**
 @brief Increases y in each iteratin, X only gets increased if decision
 * variable (ERR) is greater than zero. In that case ERR gets readjusted.
 
 * @param data The struct where data is stored.
 * @param start Starting point.
 * @param end Ending point.
 */
static void	plot_high(t_win *data, t_points *start, t_points *end)
{
	int	i;

	i = 0;
	while (i++ <= data->fdf->delta_y)
	{
		img_pix_put(&data->img, data->fdf->x, data->fdf->y, \
					get_color(data->fdf, start, end));
		if (data->fdf->err > 0)
		{
			data->fdf->x += data->fdf->slope_x;
			data->fdf->err = data->fdf->err + 2 * (data->fdf->delta_x - \
							data->fdf->delta_y);
		}
		else
			data->fdf->err = data->fdf->err + 2 * data->fdf->delta_x;
		data->fdf->y += data->fdf->slope_y;
	}
}

/**
 * @brief Get the args object using Bresenham algorithm to calculate
 * all positions.
 * 
 * @param fdf The fdf to read the data.
 * @param start The starting point.
 * @param end The ending point.
 */
static void	get_args(t_fdf *fdf, t_points *start, t_points *end)
{	
	fdf->delta_x = ft_abs(end->ix - start->ix);
	fdf->delta_y = ft_abs(end->iy - start->iy);
	if (end->ix >= start->ix)
		fdf->slope_x = 1;
	else
		fdf->slope_x = -1;
	if (end->iy >= start->iy)
		fdf->slope_y = 1;
	else
		fdf->slope_y = -1;
	fdf->x = start->ix;
	fdf->y = start->iy;
	if (fdf->delta_x > fdf->delta_y)
		fdf->err = 2 * (fdf->delta_y - fdf->delta_x);
	else
		fdf->err = 2 * (fdf->delta_x - fdf->delta_y);
}

/**
 * @brief Calculates where to plot lines.
 * 
 * @param data The data to be ploted.
 * @param start The starting point.
 * @param end The ending point.
 */
static void	plot_line(t_win *data, t_points *start, t_points *end)
{
	get_args(data->fdf, start, end);
	if (data->fdf->delta_x > data->fdf->delta_y)
		plot_low(data, start, end);
	else
		plot_high(data, start, end);
}

void	plot_map(t_win *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->fdf->height)
	{
		x = 0;
		while (x < data->fdf->width)
		{
			if (x < data->fdf->width - 1)
				plot_line(data, data->fdf->points[y][x], \
							data->fdf->points[y][x + 1]);
			if (y < data->fdf->height - 1)
				plot_line(data, data->fdf->points[y][x], \
							data->fdf->points[y + 1][x]);
			x++;
		}
	y++;
	}
}
