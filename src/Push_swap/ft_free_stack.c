/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 05:43:44 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 07:11:03 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free_stack(t_stack_node **stack)
{
    t_stack_node    *current;
    t_stack_node    *next_node;

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

void    free_error(t_stack_node **a)
{
    ft_free_stack(a);
    ft_printf("Error\n");
    exit(1);
}
