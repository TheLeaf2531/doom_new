/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 02:28:21 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:19:27 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

double	delta_ms(struct timespec start, struct timespec end)
{
	return (((end.tv_sec - start.tv_sec) * 1e+9
			+ (end.tv_nsec - start.tv_nsec)) * 1e-6);
}
