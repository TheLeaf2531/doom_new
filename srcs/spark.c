/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spark.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 08:20:57 by vboissel          #+#    #+#             */
/*   Updated: 2019/05/02 16:16:53 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.h"
#include "doom.h"
#include "default.h"

void		spark_primary(t_env *e, t_timer_handler *timer_handler)
{
	t_weapon	*weapon;

	weapon = e->p.weapon;
	if (!weapon->main_ready || !weapon->ammo)
		return ;
	Mix_PlayChannel(-1, weapon->main_sound, 0);
	weapon->main_ready = e_false;
	weapon_ray_fire(e, timer_handler);
}

t_weapon	*load_spark(t_sounds *sounds, t_map *map)
{
	t_weapon	*spark;

	if (!(spark = (t_weapon *)malloc(sizeof(t_weapon))))
		error_doom("Couldn't malloc spark");
	spark->sprites[0] = map->spark_sprite;
	spark->sprites[1] = map->spark_sprite;
	spark->sprites[2] = map->spark_sprite;
	spark->sprites_cooldown = map->spark_sprite;
	spark->sprites_fire = map->spark_sprite;
	spark->sprite_current = spark->sprites[0];
	spark->ammo = -1;
	spark->usable = e_false;
	spark->main = spark_primary;
	spark->main_cooldown = 60000;
	spark->main_ready = e_true;
	reset_animation(&spark->main_animation);
	if (!(spark->main_sound = sounds->slurp))
		error_doom("Can't load spark sound ...");
	spark->range = HORIZON;
	spark->scatter = 30;
	spark->scatter_angle = 0.785398;
	spark->damage = 500000;
	return (spark);
}
