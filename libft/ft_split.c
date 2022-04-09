/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 04:31:33 by dselmy            #+#    #+#             */
/*   Updated: 2021/09/20 00:11:01 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			num += 1;
		while (s[i] != c && s[i])
			i++;
	}
	return (num);
}

static void	free_words(char **arr, size_t num)
{
	while (num--)
	{
		if (arr && arr[num])
			free(arr[num]);
	}
	free(arr);
}

size_t	get_word_len(char const *s, char c)
{
	size_t	wordlen;

	wordlen = 0;
	while (s[wordlen] && s[wordlen] != c)
		wordlen += 1;
	return (wordlen);
}

static char	**place_words(char **arr, char const *s, char c)
{
	size_t	word_n;
	size_t	wordlen;
	size_t	i;

	word_n = 0;
	i = 0;
	while (s[i])
	{
		wordlen = 0;
		while (s[i] == c && s[i])
			i += 1;
		wordlen = get_word_len(&(s[i]), c);
		if (wordlen != 0)
		{
			arr[word_n] = ft_substr(s, i, wordlen);
			if (!arr[word_n])
			{
				free_words(arr, word_n);
				return (NULL);
			}
			word_n += 1;
			i += wordlen;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	num_words;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!arr)
		return (NULL);
	arr = place_words(arr, s, c);
	arr[num_words] = 0;
	return (arr);
}
