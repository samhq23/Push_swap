/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:48:47 by shoque            #+#    #+#             */
/*   Updated: 2025/11/12 19:55:14 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
	{
		ft_rotate(a);
		ft_rotate(b);
		ft_printf("rr\n");
	}
	ft_current_index(*a);
	ft_current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
		ft_printf("rrr\n");
	}
	ft_current_index(*a);
	ft_current_index(*b);
}
