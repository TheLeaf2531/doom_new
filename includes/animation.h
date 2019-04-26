/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 01:07:18 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 20:13:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include <SDL.h>

typedef struct s_animation		t_animation;

struct							s_animation
{
	int			x_offset;
	int			y_offset;
	double		x_resize;
	double		y_resize;
	double		duration;
	double		time;
};

void							reset_animation(t_animation *animation);
void							start_animation(t_animation *animation,
												Uint32 duration);

#endif
