/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:13:16 by harndt            #+#    #+#             */
/*   Updated: 2022/08/11 01:51:25 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	radian_ang(int angle)
{
	return ((angle * M_PI) / 180);
}

/**
 * @brief Calculates the angles for Isommetric and Diammetric projections
 * 
 * @param fdf The fdf to calculate.
 * @param point The point to calculate.
 */
static void	metric(t_fdf *fdf, t_points *point)
{
	int		previous_x;
	int		previous_y;
	double	rad;

	if (fdf->projection == ISO)
		rad = radian_ang(30);
	else
		rad = radian_ang(15);
	previous_x = point->rx;
	previous_y = point->ry;
	point->ix = fdf->controls->shift_x + (previous_x - previous_y) * cos(rad);
	point->iy = fdf->controls->shift_y + (point->rz + \
									(previous_x + previous_y) * sin(rad));
	point->color = set_color(fdf, point->pz / fdf->controls->zmod);
}

/**
 * @brief Calculates the angles to conic projection.
 * 
 * @param fdf The fdf to calculate.
 * @param point The point to calculate.
 */
static void	conic(t_fdf *fdf, t_points *point)
{
	int		previous_x;
	int		previous_y;

	previous_x = point->rx;
	previous_y = point->ry;
	point->ix = fdf->controls->shift_x + previous_x;
	point->iy = fdf->controls->shift_y + previous_y;
	point->color = set_color(fdf, point->pz / fdf->controls->zmod);
}

void	projection(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (fdf->projection == ISO || fdf->projection == DIMETRIC)
				metric(fdf, fdf->points[y][x]);
			else if (fdf->projection == CONIC)
				conic(fdf, fdf->points[y][x]);
			x++;
		}
		y++;
	}
}
