/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_states.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 06:31:13 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:18:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor_states.h"
#include "editor_panel_buttons.h"

void	new_sector_state(t_params params)
{
	((t_btn_params *)params)->ed->state = e_add_sector;
}

void	create_enemy_in_map_state(t_params params)
{
	((t_btn_params *)params)->ed->state = e_add_enemy;
}

void	create_object_in_map_state(t_params params)
{
	((t_btn_params *)params)->ed->state = e_add_object;
}

void	create_pickable_in_map_state(t_params params)
{
	((t_btn_params *)params)->ed->state = e_add_pickable;
}

void	add_lever_state(t_params params)
{
	((t_btn_params *)params)->ed->state = e_add_lever;
}