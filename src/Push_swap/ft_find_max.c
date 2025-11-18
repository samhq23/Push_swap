/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:33:00 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 13:32:16 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack_node	*ft_find_max(t_stack_node *s)
{
	t_stack_node	*max_node;

	if (!s)
		return (NULL);
	max_node = s;
	while (s)
	{
		if (s->value > max_node->value)
			max_node = s;
		s = s->next;
	}
	return (max_node);
}
