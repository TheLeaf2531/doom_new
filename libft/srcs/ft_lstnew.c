/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:04:47 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/25 18:18:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*knot;

	if (!(knot = (t_list*)malloc(sizeof(*knot))))
		return (NULL);
	if (content == NULL)
	{
		knot->content = NULL;
		knot->content_size = 0;
	}
	else
	{
		knot->content = ft_memdup(content, content_size);
		knot->content_size = content_size;
	}
	knot->next = NULL;
	return (knot);
}
