/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcleni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 00:05:15 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:18:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcleni(const char *s, int start, char c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[start + i] && s[start + i] != c)
			i++;
		return (i);
	}
	return (0);
}
