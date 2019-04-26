/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:07:31 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:18:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	end;
	size_t	len;

	if (s)
	{
		i = 0;
		end = ft_strlen(s) - 1;
		while (s[i] && (s[i] == '\n' || ft_isblank(s[i])))
			i++;
		while (s[end] && (s[end] == '\n' || ft_isblank(s[end])))
			end--;
		if (i == ft_strlen(s))
			return (ft_strdup(""));
		len = end + 1 - i;
		return (ft_strsub(s, i, len));
	}
	return (NULL);
}
