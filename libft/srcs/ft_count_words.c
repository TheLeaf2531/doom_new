/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:23:43 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:18:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	if (s)
	{
		i = 0;
		count = 0;
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (i > 1 && s[i - 1] == c)
			count--;
		return (count);
	}
	return (0);
}
