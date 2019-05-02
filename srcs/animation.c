/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 01:32:43 by vboissel          #+#    #+#             */
/*   Updated: 2019/05/01 16:16:00 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "weapon.h"

enum e_bool	unlock(double deltatime, t_params ready)
{
	(void)deltatime;
	*(enum e_bool *)ready = e_true;
	return (e_false);
}

enum e_bool	animate_door(double deltatime, t_params params)
{
	t_door_animation	*animation;

	animation = (t_door_animation *)params;
	animation->elapsed_time += deltatime;
	animation->door->wall_offset = (animation->elapsed_time
			/ animation->total_time * animation->target_offset);
	if (animation->elapsed_time >= animation->total_time)
	{
		if (!animation->door->to_infinity)
			animation->door->type = e_portal;
		free(animation);
		return (e_false);
	}
	return (e_true);
}

void		reset_animation(t_animation *animation)
{
	*animation = (t_animation){(int)0, (int)0, (double)1,
						(double)1, (double)0, (double)0};
}

void		start_animation(t_animation *animation, Uint32 duration)
{
	animation->time = 0;
	animation->duration = duration;
}
