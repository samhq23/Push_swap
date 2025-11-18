/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0004/01/01 00:00:00 by >                 #+#    #+#             */
/*   Updated: 2025/11/18 13:31:22 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = ft_stack_len(*a);
	if (len > 3)
	{
		pb(a, b);
		len--;
	}
	if (len-- > 3)
		pb(a, b);
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
