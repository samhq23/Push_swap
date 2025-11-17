/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:14:03 by shoque            #+#    #+#             */
/*   Updated: 2025/11/15 04:26:44 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_rev_rotate(t_stack_node **s)
{
	t_stack_node	*end_node;

	if ((!*s) || (*s)->next == NULL)
		return ;
	end_node = ft_find_end(*s);
	end_node->prev->next = NULL;
	end_node ->next = *s;
	end_node->prev = NULL;
	*s = end_node;
	end_node->next->prev = end_node;
}

void	rra(t_stack_node **a)
{
	ft_rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	ft_rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}
