/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:28:37 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 07:07:28 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node    *ft_find_min(t_stack_node *s)
{
    t_stack_node    *min_node;

    if (!s)
        return (NULL);
    min_node = s;
    while (s)
    {
        if (s->value < min_node->value)
            min_node = s;
        s = s->next;
    }
    return (min_node);
}
