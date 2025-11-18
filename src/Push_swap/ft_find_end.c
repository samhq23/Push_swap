/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:19:58 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 07:07:18 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"   

t_stack_node    *ft_find_end(t_stack_node **s)
{
    t_stack_node    *current;

    if (!*s)
        return (NULL);
    current = *s;
    while (current->next)
        current = current->next;
    return (current);
}
