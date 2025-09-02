/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:02:30 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 19:04:52 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(const char *s, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == c)
			in_substring = 0;
		s++;
	}
	return (count);
}

char	*word_creator(const char **s, char c)
{
	const char	*start;
	char		*word;
	size_t		len;

	while (**s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

void	free_all(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		pos;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!str)
		return (NULL);
	pos = 0;
	while (*s != '\0')
	{
		str[pos] = word_creator(&s, c);
		if (!str[pos])
		{
			free_all(str, pos);
			return (NULL);
		}
		if (str[pos][0] == '\0')
			free(str[pos]);
		else
			pos++;
	}
	str[pos] = NULL;
	return (str);
}

/* int	main(void)
{
	char *s = "  This is a    string to split  ";
	char c = ' ';
	char **ptr = ft_split(s, c);
	int i = 0;

	while (ptr[i])
	{
		printf("ptr[%d]: %s\n", i, ptr[i]);
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}  */