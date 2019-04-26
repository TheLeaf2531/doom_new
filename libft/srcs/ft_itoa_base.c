/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:19:18 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:18:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	unsigned int	ncpy;
	size_t			len;
	char			*nbinstr;
	char			*strbase;

	ncpy = ft_abs(n);
	len = ft_nbrlen(n, base);
	if (!(nbinstr = ft_strnew(len)))
		return (NULL);
	strbase = "0123456789ABCDEF";
	if (n < 0 && base == 10)
		nbinstr[0] = '-';
	else if (n == 0)
		nbinstr[0] = '0';
	nbinstr[len] = '\0';
	while (ncpy > 0)
	{
		nbinstr[len - 1] = strbase[ncpy % base];
		ncpy /= base;
		len--;
	}
	return (nbinstr);
}
