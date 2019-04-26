/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_motion.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:07:09 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 20:16:56 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORIZONTAL_MOTION_H
# define HORIZONTAL_MOTION_H

# include "utils.h"
# include "sectors.h"

t_coords	allowed_move(t_vector speed, t_coords position,
				t_sector **current_sector);

#endif
