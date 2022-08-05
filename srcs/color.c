/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:24:15 by harndt            #+#    #+#             */
/*   Updated: 2022/08/05 01:02:09 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_color(t_fdf *fdf, int z)
{
	if (!fdf->controls->color)
		return (C_NIER_TXT);
	else
	{
		if (z >= 8 || z <= -8)
			if (z >= 8)
				return (C_NIER_WHITE);
		else
			return (C_BLU);
		else if (z >= 4 || z <= -4)
			if (z >= 4)
				return (C_NIER_YELLOW);
		else
			return (C_ORG);
		else if (z >= 2 || z <= -2)
			if (z >= 2)
				return (C_NIER_BEIGE);
		else
			return (C_NIER_BROWN);
		else if (z > 0 || z < 0)
			if (z >= 0)
				return (C_NIER_TXT);
		else
			return (C_NIER_BROWN);
		else
			return (C_NIER_BROWN);
	}
}


/**
 * @brief Get the light color.
 * 
 * @param start Starting point.
 * @param end Ending point.
 * @param percentage Calculated percentage.
 * @return int Return the color.
 */
static int	get_light(int start, int end, double percentage)
{
	return ((int)(1 - percentage) * start + percentage * end);
}

/**
 * @brief Get the percent object
 * 
 * @param start Starting point
 * @param end Ending point.
 * @param current Current point.
 * @return double The porcentage of the line position.
 */
static double	get_percent(int start, int end, int current)
{
	double	placemant;
	double	distance;

	placemant = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placemant / distance);
}

int	get_color(t_fdf *fdf, t_points *start, t_points *end)
{
	int	r;
	int	g;
	int	b;
	int	percentage;

	if (start->color == end->color)
		return (end->color);
	if (fdf->delta_x > fdf->delta_y)
		percentage = get_percent(start->ix, end->ix, fdf->x);
	else
		percentage = get_percent(start->iy, end->iy, fdf->y);
	r = get_light((start->color >> 16) & 0xFF, \
					(end->color >> 16) & 0xFF, percentage);
	g = get_light((start->color >> 8) & 0xFF, \
					(end->color >> 8) & 0xFF, percentage);
	b = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
	return (r << 16 | g << 8 | b);
}
