/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:07:46 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/30 22:12:51 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include "timer_handler.h"
#include <SDL.h>
#include "default.h"
#include "render.h"
#include "render_blackhole.h"
#include "surface_manipulation.h"
#include "ui.h"
#include <math.h>

enum e_bool	day_to_night(double ms_since_update, t_params daytime)
{
	(void)ms_since_update;
	if (*(enum e_bool *)daytime)
		*(enum e_bool *)daytime = e_false;
	else
		*(enum e_bool *)daytime = e_true;
	return (e_true);
}

void		skybox(const t_render *render, t_u_range range)
{
	Uint32		y;
	Uint32		end;
	Uint32		color_text;
	t_coords	draw_text;

	y = range.start;
	end = range.end;
	draw_text.x = (int)(render->sky->w / CIRCLE * render->heading + render->x)
			% render->sky->w;
	while (y < end)
	{
		draw_text.y = (fabs((render->win_h - 1)
				- fabs(render->vision_height - y))
			* render->sky->h / render->win_h);
		color_text = get_pixel(render->sky, draw_text.x, draw_text.y, e_true);
		put_pixel_blackhole(render->bandaid, render->x, y, color_text);
		y++;
	}
}
