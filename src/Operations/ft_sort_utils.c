/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:23:26 by shoque            #+#    #+#             */
/*   Updated: 2025/11/18 13:31:43 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rr(a, b);
	ft_current_index(*a);
	ft_current_index(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rrr(a, b);
	ft_current_index(*a);
	ft_current_index(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = ft_find_cheapest_node(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		rev_rotate_both(a, b, cheapest);
	ft_prep_for_push(a, cheapest, 'a');
	ft_prep_for_push(b, cheapest->target_node, 'b');
	pb(a, b);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	if (!*b)
		return ;
	ft_prep_for_push(a, (*b)->target_node, 'a');
	pa(b, a);
}

void	min_to_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = ft_find_min(*a);
	ft_current_index(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}
