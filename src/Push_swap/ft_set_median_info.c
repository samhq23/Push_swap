/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_median_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:41:01 by farhan            #+#    #+#             */
/*   Updated: 2025/11/16 18:42:10 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    ft_set_median_info(t_stack_node *s)
{
    int median;
    int size;
    int i;

    size = ft_stack_len(s);
    median = size / 2;
    i = 0;
    while (s)
    {
        if (i <= median)
            s->above_median = 1;
        else
            s->above_median = 0;
        s = s->next;
        i++;
    }
}   