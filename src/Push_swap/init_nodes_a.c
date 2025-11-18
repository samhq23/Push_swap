/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:08:20 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 13:33:00 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;

	current = a;
	ft_current_index(a);
	ft_current_index(b);
	while (current)
	{
		current->target_node = ft_find_target_node(b, current->value);
		current = current->next;
	}
	ft_set_cost(a, b);
}
