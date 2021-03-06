/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:41:59 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:19:27 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <math.h>
#include "utils.h"
#include "e_bool.h"
#include "libft.h"
#include "collision.h"
#include "player.h"
#include "default.h"
#include "doom.h"
#include "player.h"
#include "render.h"

t_sector		*get_next_sector_addr(t_sector *current, t_wall *wall)
{
	if (wall->to_infinity)
		return (NULL);
	if (wall->links.sector1 == current)
		return (wall->links.sector2);
	else if (wall->links.sector2 == current)
		return (wall->links.sector1);
	return (NULL);
}
