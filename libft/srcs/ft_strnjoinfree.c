/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:04:08 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:18:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnjoinfree(char const *s1, char const *s2, size_t len, int opt)
{
	char	*str;

	str = ft_strnjoin(s1, s2, len);
	if (s1 && (opt & 1))
		free((void*)s1);
	if (s2 && (opt & 2))
		free((void*)s2);
	return (str);
}
