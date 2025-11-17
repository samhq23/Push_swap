/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0004/01/01 00:00:00 by >                 #+#    #+#             */
/*   Updated: 2025/11/16 22:05:45 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
	{
		ra(a);
        rb(b);
		ft_printf("rr\n");
	}
	ft_current_index(*a);
	ft_current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
	{
		ra(a);
		rb(b);
		ft_printf("rrr\n");
	}
	ft_current_index(*a);
	ft_current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
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

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ft_prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	min_to_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = ft_find_min(*a);
	ft_current_index(*a);
	ft_set_median_info(*a);
	while (*a != min)
	{
		if (min->above_median)
			ft_rotate(a);
		else
			ft_rev_rotate(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = ft_stack_len(*a);
	if (len > 3)
	{
		pb(a, b);
		len--;
	}
	if (len > 3)
	{
		pb(a, b);
		len--;
	}
	while (len > 3)
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
		len--;
	}
	ft_sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	min_to_top(a);
}

	