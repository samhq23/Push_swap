/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:43:07 by shoque            #+#    #+#             */
/*   Updated: 2025/11/18 13:31:09 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_push(t_stack_node **s, t_stack_node **d)
{
	t_stack_node	*temp;

	if (!*s)
		return ;
	temp = *s;
	*s = (*s)->next;
	if (*s)
		(*s)->prev = NULL;
	temp->prev = NULL;
	if (!*d)
	{
		*d = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *d;
		temp->next->prev = temp;
		*d = temp;
	}
}

void	pa(t_stack_node **stack_b, t_stack_node **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
