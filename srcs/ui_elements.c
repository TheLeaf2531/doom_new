/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_elements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 00:34:37 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/30 22:43:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "libft.h"
#include "default.h"
#include "utils.h"
#include "surface_manipulation.h"
#include "config.h"
#include "ui.h"

void	draw_crosshair(SDL_Surface *surface, t_config *op, Uint32 color)
{
	t_segment	segment;

	segment = (t_segment) {op->half_w, op->half_h - 5,
							op->half_w, op->half_h - 5 - 5};
	draw_segment(surface, segment, color);
	segment = (t_segment) {op->half_w - 5, op->half_h,
							op->half_w - 5 - 5, op->half_h};
	draw_segment(surface, segment, color);
	segment = (t_segment) {op->half_w, op->half_h + 5,
							op->half_w, op->half_h + 5 + 5};
	draw_segment(surface, segment, color);
	segment = (t_segment) {op->half_w + 5, op->half_h,
							op->half_w + 5 + 5, op->half_h};
	draw_segment(surface, segment, color);
	put_pixel_alpha(surface, op->half_w, op->half_h, color);
}

void	draw_fps(TTF_Font *font, SDL_Surface *surface, int fps)
{
	SDL_Surface	*fps_text;
	t_i_coords	pos;
	char		*fps_str;

	pos = (t_i_coords) {(int)10, (int)10};
	fps_str = ft_strjoinfree(ft_itoa(fps), " fps", 1);
	fps_text = write_text(font, fps_str, (SDL_Colour){255, 255, 255, 255});
	free(fps_str);
	draw_on_screen(surface, fps_text, pos, e_false);
	SDL_FreeSurface(fps_text);
}

void	draw_health(t_env *e)
{
	SDL_Surface	*health_text;
	t_i_coords	pos;
	char		*health_str;

	pos = (t_i_coords){e->op.half_w - 150, e->op.win_h - 45};
	health_str = ft_itoa((int)e->p.health);
	health_text = write_text(e->fonts->sixty40, health_str,
			(SDL_Colour){244, 182, 66, 255});
	free(health_str);
	draw_on_screen(e->doom.surface, health_text, pos, e_false);
	SDL_FreeSurface(health_text);
	if (e->map->hud.id > 2 || e->p.dead)
		e->map->hud.id = 0;
	pos = (t_i_coords){e->op.half_w - 200, e->op.win_h - 50};
	draw_on_screen(e->doom.surface,
			e->map->hud.cross[e->map->hud.id], pos, e_false);
}

void	draw_ammo(t_env *e, SDL_Surface *bullet, int ammo)
{
	SDL_Surface	*ammo_nb;
	t_i_coords	pos;
	char		*charlatan;

	pos = (t_i_coords){e->op.half_w + 300, e->op.win_h - 45};
	if (ammo == -1)
	{
		pos.y = e->op.win_h - 35;
		charlatan = ft_itoa(8);
		ammo_nb = write_text(e->fonts->vcr40, charlatan,
				(SDL_Colour){0, 0, 0, 255});
		rotate_and_draw(e->doom.surface, ammo_nb, pos, e_false);
	}
	else
	{
		charlatan = ft_itoa(ammo);
		ammo_nb = write_text(e->fonts->vcr40, charlatan,
				(SDL_Colour){0, 0, 0, 255});
		draw_on_screen(e->doom.surface, ammo_nb, pos, e_false);
	}
	free(charlatan);
	SDL_FreeSurface(ammo_nb);
	pos.x = e->op.half_w + 350;
	pos.y = e->op.win_h - 52;
	draw_on_screen(e->doom.surface, bullet, pos, e_false);
}
