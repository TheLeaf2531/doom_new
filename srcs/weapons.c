/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 00:14:32 by vboissel          #+#    #+#             */
/*   Updated: 2019/05/01 20:59:48 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include "collision.h"
#include "weapon.h"
#include "book.h"
#include "melee.h"

void		make_weapon_usable(t_weapons *node, Uint32 target)
{
	Uint32	i;

	i = 0;
	while (node && i < target)
	{
		node = node->next;
		i++;
	}
	node->item->usable = e_true;
	if (node->item->ammo >= 0)
		node->item->ammo += 10;
}

t_weapon	*get_weapon(t_weapons *node, Uint32 target)
{
	Uint32	i;

	i = 0;
	while (node && i < target)
	{
		node = node->next;
		i++;
	}
	return (node->item);
}

void		put_weapon(t_weapons *node, t_weapon *weapon, Uint32 target)
{
	Uint32	i;

	i = 0;
	while (node && i < target)
	{
		node = node->next;
		i++;
	}
	node->item = weapon;
}

t_weapons	*allocate_weapons(t_sounds *sounds, t_map *map)
{
	t_weapons	*node;
	t_weapons	*first;

	if (!(node = (t_weapons *)malloc(sizeof(t_weapons))))
		error_doom("Couldn't allocate weapons");
	first = node;
	node->item = load_book(sounds, map);
	if (!(node->next = (t_weapons *)malloc(sizeof(t_weapons))))
		error_doom("Couldn't allocate weapons");
	node = node->next;
	node->next = NULL;
	node->item = load_book(sounds, map);
	if (!(node->next = (t_weapons *)malloc(sizeof(t_weapons))))
		error_doom("Couldn't allocate weapons");
	node = node->next;
	node->next = NULL;
	node->item = load_staff(sounds, map);
	if (!(node->next = (t_weapons *)malloc(sizeof(t_weapons))))
		error_doom("Couldn't allocate weapons");
	node = node->next;
	node->next = NULL;
	node->item = load_spark(sounds, map);
	return (first);
}

void		free_weapons(t_weapons *weapons)
{
	t_weapons	*n;
	t_weapons	*p;

	n = weapons;
	while (n)
	{
		free(n->item);
		p = n;
		n = n->next;
		free(p);
	}
}
