/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:16:33 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 07:06:56 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_swap(t_stack_node **s)
{
    t_stack_node	*first;
    t_stack_node	*second;
    t_stack_node    *third;

    if (!*s || (*s)->next == NULL)
        return ;
    first = *s;
    second = first->next;
    third = second->next;
    *s = second;
    (*s)->prev = NULL;
    (*s)->next = first;
    first->prev = *s;
    first->next = third;
    if (third)
        third->prev = first;
}

void    sa(t_stack_node **a)
{
    ft_swap(a);
    ft_printf("sa\n");
}

void    sb(t_stack_node **b)
{
    ft_swap(b);
    ft_printf("sb\n");
}

void    ss(t_stack_node **a, t_stack_node **b)
{
    ft_swap(a);
    ft_swap(b);
    ft_printf("ss\n");
}
