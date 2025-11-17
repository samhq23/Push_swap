/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:24:52 by farhan            #+#    #+#             */
/*   Updated: 2025/11/16 18:26:13 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int    ft_is_sorted(t_stack_node *s)
{
    if (!s)
        return (1);
    while (s->next)
    {
        if (s->value > s->next->value)
            return (0);
        s = s->next;
    }
    return (1);
}
