/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 00:44:00 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/30 22:45:09 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "map.h"
#include "doom.h"
#include "ui.h"
#include "default.h"

void		draw_sun_or_moon(SDL_Surface *surface, t_map *map, t_config *op)
{
	t_i_coords pos;

	pos.x = op->win_w - 50;
	pos.y = 0;
	if (map->daytime)
		draw_on_screen(surface, map->hud.sun, pos, e_true);
	else
		draw_on_screen(surface, map->hud.moon, pos, e_true);
}

void		ui_draw(SDL_Surface *surface, t_map *map, int fps, t_env *e)
{
	draw_crosshair(surface, &e->op, CROSSHAIR_COLOR);
	draw_fps(e->fonts->sixty20, surface, fps);
	draw_sun_or_moon(surface, map, &e->op);
	draw_health(e);
	draw_ammo(e, map->hud.bullet, e->p.weapon->ammo);
	draw_face(surface, &map->hud, &e->p, &e->op);
}
