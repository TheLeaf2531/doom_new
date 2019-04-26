/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_bool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 02:44:38 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 20:15:08 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_BOOL_H
# define E_BOOL_H

enum	e_bool
{
	e_false = 0,
	e_true = 1
};

enum e_bool	invert_bool(enum e_bool bool);

#endif
