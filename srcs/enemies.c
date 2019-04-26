/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 07:09:41 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:18:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL_mixer.h>
#include "enemies.h"
#include "doom.h"

void	free_enemies(t_linked_enemies *enemies)
{
	if (!enemies)
		return ;
	free_enemies(enemies->next);
	free(enemies->item.object);
	free(enemies);
}

void	add_enemy(t_linked_enemies **linked_enemies, t_linked_enemies *enemy)
{
	t_linked_enemies	*n;

	if (!*linked_enemies)
	{
		*linked_enemies = enemy;
		return ;
	}
	n = *linked_enemies;
	while (n->next)
		n = n->next;
	n->next = enemy;
}
