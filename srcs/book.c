/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 08:31:09 by vboissel          #+#    #+#             */
/*   Updated: 2019/05/02 16:16:25 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.h"
#include "doom.h"
#include "default.h"

enum e_bool	book_idle_anim(double ms_since_update, t_params params)
{
	t_weapon	*book;
	int			step;

	book = (t_weapon *)params;
	if (!book->main_ready)
		return (e_false);
	book->animation.time += ms_since_update;
	if (book->animation.time >= book->animation.duration)
		book->animation.time = 0;
	step = (int)(book->animation.time) / (int)(book->animation.duration / 3);
	if (step >= 3)
		step = 2;
	book->sprite_current = book->sprites[step];
	return (e_true);
}

enum e_bool	book_firing(double ms_since_update, t_params params)
{
	t_weapon_and_timer	*ptr;

	ptr = (t_weapon_and_timer *)params;
	ptr->weapon->main_animation.time += ms_since_update;
	if (ptr->weapon->main_animation.time >= ptr->weapon->main_cooldown)
	{
		add_event(ptr->timer_handler, 5, &book_idle_anim, ptr->weapon);
		free(ptr);
		return (e_false);
	}
	if (ptr->weapon->main_animation.time <= 200)
		ptr->weapon->sprite_current = ptr->weapon->sprites_fire;
	else
		ptr->weapon->sprite_current = ptr->weapon->sprites_cooldown;
	return (e_true);
}

void		book_primary(t_env *e, t_timer_handler *timer_handler)
{
	t_weapon_and_timer	*params;
	t_weapon			*weapon;

	weapon = e->p.weapon;
	if (!weapon->main_ready || !weapon->ammo)
		return ;
	Mix_PlayChannel(-1, weapon->main_sound, 0);
	weapon->main_ready = e_false;
	weapon->ammo--;
	reset_animation(&weapon->main_animation);
	weapon->main_animation.duration = weapon->main_cooldown;
	if (!(params = (t_weapon_and_timer *)malloc(sizeof(t_weapon_and_timer))))
		error_doom("Couldn't malloc params for firing");
	params->weapon = weapon;
	params->timer_handler = timer_handler;
	weapon_ray_fire(e, timer_handler);
	add_event(timer_handler, 1, &book_firing, params);
	add_event(timer_handler, weapon->main_cooldown, &unlock,
			&weapon->main_ready);
}

void		load_book_sprites(t_weapon *weapon, t_map *map)
{
	Uint32	i;

	i = 0;
	while (i < 3)
	{
		weapon->sprites[i] = map->book_sprites[i];
		i++;
	}
	weapon->sprite_current = weapon->sprites[0];
	weapon->sprites_fire = map->book_sprites[3];
	weapon->sprites_cooldown = map->book_sprites[4];
}

t_weapon	*load_book(t_sounds *sounds, t_map *map)
{
	t_weapon *book;

	if (!(book = (t_weapon *)malloc(sizeof(t_weapon))))
		error_doom("Couldn't malloc book");
	load_book_sprites(book, map);
	book->ammo = 0;
	book->main = NULL;
	book->usable = e_false;
	reset_animation(&book->animation);
	book->animation.duration = 500;
	book->main = book_primary;
	book->main_cooldown = 500;
	reset_animation(&book->main_animation);
	book->main_ready = e_true;
	if (!(book->main_sound = sounds->zap))
		error_doom("Can't load book sound ...");
	book->range = HORIZON;
	book->scatter = 2;
	book->scatter_angle = 2;
	book->damage = 30;
	return (book);
}
