/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_target_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:59:47 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 13:32:27 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack_node	*ft_find_target_node(t_stack_node *a, int b_value)
{
	t_stack_node	*target;
	t_stack_node	*min_node;

	target = NULL;
	min_node = ft_find_min(a);
	while (a)
	{
		if (a->value > b_value)
		{
			if (!target || a->value < target->value)
				target = a;
		}
		a = a->next;
	}
	if (!target)
		target = min_node;
	return (target);
}
