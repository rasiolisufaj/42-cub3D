/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:02:29 by raisufaj          #+#    #+#             */
/*   Updated: 2024/11/18 13:29:23 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		words++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (words);
}

static int	get_words(char **tab, char const *s, char c)
{
	int		index;
	size_t	len;
	int		i;

	index = 0;
	i = 0;
	while (s[index])
	{
		len = 0;
		while (s[index + len] != c && s[index + len])
			len++;
		tab[i] = ft_substr(s, index, len);
		if (!tab[i])
		{
			while (--i >= 0)
				free(tab[i]);
			return (0);
		}
		while (s[index + len] == c && s[index + len])
			len++;
		i++;
		index += len;
	}
	return (1);
}

static void	*free_clean(char *cleanstr, char **tab)
{
	free(cleanstr);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	*cleanstr;
	char	cleaner[2];
	int		nbstr;
	char	**tab;

	cleaner[0] = c;
	cleaner[1] = 0;
	cleanstr = ft_strtrim(s, cleaner);
	if (!cleanstr)
		return (NULL);
	nbstr = count_words(cleanstr, c);
	tab = malloc(nbstr * sizeof(char *) + sizeof(NULL));
	if (!tab)
	{
		free(cleanstr);
		return (NULL);
	}
	if (!get_words(tab, cleanstr, c))
		free_clean(cleanstr, tab);
	tab[nbstr] = NULL;
	free(cleanstr);
	return (tab);
}

/*#include <stdio.h>

int	main()
{
	char *str = "Hello everyone! Testing split for Libft!";
	char sep = ' ';
	char **result = ft_split(str, sep);
	int	i = 0;
	while (result[i] != NULL)
	{
		printf("Word %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}

	free(result);
	return (0);
}*/