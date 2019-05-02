/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 09:18:07 by vboissel          #+#    #+#             */
/*   Updated: 2019/05/01 16:39:05 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "textures.h"
#include "doom.h"
#include "sectors.h"

void			free_objects(t_objects *objects)
{
	if (objects->count > 0)
		free(objects->items);
	free(objects);
}

t_segment		set_segment(double x1, double y1, double x2, double y2)
{
	t_segment t;

	t = (t_segment){(double)x1, (double)y1, (double)x2, (double)y2};
	return (t);
}

t_segment		perpendicular_segment_from_point(t_object *object,
		double point_of_view_x, double point_of_view_y)
{
	t_vector	view;
	t_vector	perpendicular_view;
	t_segment	segment;

	view = (t_vector){(double)(object->x - point_of_view_x),
								(double)(object->y - point_of_view_y)};
	normalize_vector(&view);
	perpendicular_view = (t_vector){(double)view.y, -view.x};
	scalar_multiply(&perpendicular_view, object->horizontal_size / 2.0);
	segment = set_segment(object->x - perpendicular_view.x,
							object->y - perpendicular_view.y,
							object->x + perpendicular_view.x,
							object->y + perpendicular_view.y);
	return (segment);
}
