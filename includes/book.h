/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:06:45 by vboissel          #+#    #+#             */
/*   Updated: 2019/05/02 16:18:07 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOK_H
# define BOOK_H

# include "sounds.h"

t_weapon	*load_book(t_sounds *sounds, t_map *map);
t_weapon	*load_staff(t_sounds *sounds, t_map *map);
t_weapon	*load_spark(t_sounds *sounds, t_map *map);
enum e_bool book_idle_anim(double ms_since_update, t_params params);

#endif
