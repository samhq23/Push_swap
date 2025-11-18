/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:11:14 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 13:31:58 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_current_index(t_stack_node *s)
{
	int	i;
	int	median;

	median = ft_stack_len(s) / 2;
	if (!s)
		return ;
	i = 0;
	while (s)
	{
		s->current_index = i;
		if (i <= median)
			s->above_median = 1;
		else
			s->above_median = 0;
		s = s->next;
		i++;
	}
}
