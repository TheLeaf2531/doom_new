/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_panel_buttons.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 06:33:26 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:18:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include "editor_panel_buttons.h"

t_btn_params	*create_btn_params(SDL_Surface **selected, SDL_Surface *target,
					t_editor *ed)
{
	t_btn_params	*params;

	if (!(params = (t_btn_params *)malloc(sizeof(t_btn_params))))
		error_doom("Couldn't malloc button params");
	params->selected = selected;
	params->target = target;
	params->ed = ed;
	return (params);
}

void			add_button_to_list(t_buttons **list, t_button button)
{
	t_buttons	*new_node;
	t_buttons	*node;

	if (!(new_node = (t_buttons *)malloc(sizeof(t_buttons))))
		error_doom("Couldn't malloc button");
	new_node->item = button;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	node = *list;
	while (node->next)
		node = node->next;
	node->next = new_node;
}

void			free_buttons_list(t_buttons *node)
{
	t_buttons	*next;

	while (node)
	{
		next = node->next;
		free(node->item.params);
		free(node);
		node = next;
	}
}
