/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   melee.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:23:19 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 20:17:32 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MELEE_H
# define MELEE_H

# include "sounds.h"

void		fuck_flower(t_player *p, t_object *object);
t_weapon	*load_melee(t_sounds *sounds, t_map *map);
void		melee_primary(t_player *player, t_timer_handler *timer_handler);

#endif
