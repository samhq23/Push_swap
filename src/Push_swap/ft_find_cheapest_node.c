/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cheapest_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:47:03 by farhan            #+#    #+#             */
/*   Updated: 2025/11/16 21:48:23 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    *ft_find_cheapest_node(t_stack_node *s)
{
    t_stack_node    *cheapest;
    long int        lower_cost;

    if (!s)
        return (NULL);
    cheapest = s;
    lower_cost = LONG_MAX;
    while (s)
    {
        if (s->total_cost < lower_cost)
        {
            lower_cost = s->total_cost;
            cheapest = s;
        }
        s = s->next;
    }
    return (cheapest);
}
