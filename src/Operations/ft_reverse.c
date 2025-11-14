/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:28:09 by shoque            #+#    #+#             */
/*   Updated: 2025/11/12 19:36:28 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_rotate(t_stack_node **s)
{
	t_stack_node	*start_node;

	if ((!*s) || (*s)->next == NULL)
		return ;
	start_node = *s;
	end_node = ft_find_end(*s);
	*s = start_node->next;
	*s->prev = NULL;
	start_node->next = NULL;
	start_node->prev = end_node;
	end_node->next = start_node;
}

void	ra(t_stack_node **a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
