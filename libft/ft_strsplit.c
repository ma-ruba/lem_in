/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:42:17 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 20:42:19 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int		i;
	int		count_word;

	i = 0;
	count_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count_word++;
		i++;
	}
	return (count_word);
}

static char	**ft_mem(char const *s, char c, char **arr)
{
	int i;
	int count_word;
	int count;

	i = 0;
	count = 0;
	count_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				arr[count_word] = (char*)malloc((count + 1) * sizeof(char));
				if (arr[count_word] == NULL)
					return (NULL);
				count_word++;
				count = 0;
			}
		}
		i++;
	}
	return (arr);
}

static char	**ft_split_cpy(const char *s, char c, char **arr)
{
	int		i;
	int		count_word;
	int		j;

	i = 0;
	count_word = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			arr[count_word][j] = s[i];
			j++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				arr[count_word][j] = '\0';
				count_word++;
				j = 0;
			}
		}
		i++;
	}
	arr[count_word] = NULL;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = ft_mem(s, c, arr);
	arr = ft_split_cpy(s, c, arr);
	return (arr);
}
