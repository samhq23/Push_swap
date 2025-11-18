/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:19:58 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 13:32:51 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_set_cost(t_stack_node *a, t_stack_node *b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*current;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	current = a;
	while (current)
	{
		if (current->above_median)
			current->cost_a = current->current_index;
		else
			current->cost_a = current->current_index - len_a;
		if (current->target_node->above_median)
			current->cost_b = current->target_node->current_index;
		else
			current->cost_b = current->target_node->current_index - len_b;
		current->total_cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
		current = current->next;
	}
}
