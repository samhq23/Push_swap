/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:23:15 by shoque            #+#    #+#             */
/*   Updated: 2025/11/18 17:20:58 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	count_words(const char *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && !ft_isspace(s[i]))
				i++;
		}
	}
	return (words);
}

static int	fill_split(char **arr, const char *s, int words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		len = 0;
		while (s[i + len] && !ft_isspace(s[i + len]))
			len++;
		arr[j] = ft_substr(s, i, len);
		if (!arr[j])
			return (0);
		i += len;
		j++;
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s);
	if (words == 0)
		return (NULL);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_split(arr, s, words))
		return (NULL);
	return (arr);
}
