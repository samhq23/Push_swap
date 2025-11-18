/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:06:29 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 07:06:53 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_three(t_stack_node **a)
{
    t_stack_node    *biggest_node;

    biggest_node = ft_find_max(*a);

    if (biggest_node == *a)
        ra(a);
    else if ((*a)->next == biggest_node)
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}
