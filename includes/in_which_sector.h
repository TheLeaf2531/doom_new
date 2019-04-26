/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_which_sector.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:07:54 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 20:17:03 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_WHICH_SECTOR_H
# define IN_WHICH_SECTOR_H

# include "sectors.h"

int			is_in_sector(t_coords pos, t_sector *sector);
t_sector	*in_which_sector(t_coords pos, t_sectors *sectors);
void		rotate_segment_around_first_extremity(t_segment *segment,
				const double angle);
enum e_bool	line_through_segment_intersects_a_sector_vertex(t_segment segment,
				t_sector *sector);

#endif
