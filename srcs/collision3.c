/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:53:22 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:19:27 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "default.h"

void			free_collisions(t_collisions *collisions)
{
	t_collisions	*buffer;

	while (collisions)
	{
		buffer = collisions->next;
		free(collisions);
		collisions = buffer;
	}
}
