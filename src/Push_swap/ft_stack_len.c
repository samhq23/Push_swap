/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:23:59 by farhan            #+#    #+#             */
/*   Updated: 2025/11/16 18:42:19 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int    ft_stack_len(t_stack_node *s)
{
    int    size;

    size = 0;
    if (!s)
        return (0);
    while (s)
    {
        s = s->next;
        size++;
    }
    return (size);
}
