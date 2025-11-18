/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 05:43:44 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 13:32:32 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		current->value = 0;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

void	free_error(t_stack_node **a)
{
	ft_free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
