/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_for_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:06:32 by farhan            #+#    #+#             */
/*   Updated: 2025/11/16 19:41:40 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    ft_prep_for_push(t_stack_node **s, t_stack_node *node, char stack_name)
{
    if (stack_name == 'a')
    {
        while (*s != node)
        {
            if (node->above_median)
                ra(s);
            else
                rra(s);
        }
    }
    else if (stack_name == 'b')
    {
        while (*s != node)
        {
            if (node->above_median)
                rb(s);
            else
                rrb(s);
        }
    }
}
