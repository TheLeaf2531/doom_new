/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_states.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 04:59:24 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 20:16:03 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_STATES_H
# define EDITOR_STATES_H

# include "timer_handler.h"

void		new_sector_state(t_params params);
void		create_enemy_in_map_state(t_params params);
void		create_pickable_in_map_state(t_params params);
void		create_object_in_map_state(t_params params);
void		add_lever_state(t_params params);

#endif
