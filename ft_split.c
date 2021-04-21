/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:54:46 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/20 17:24:27 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ppfree(char **res, int i)
{
	while (i > 0)
	{
		free(res[i - 1]);
		i--;
	}
	free(res);
}

//counting len of str, while char c is not appear
static int	strclen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

//counting number of words
static int	num_of_words(char const *s, char c)
{
	int	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			num++;
		}
		if (*s != 0)
			s++;
	}
	return (num);
}

static int	copier(char **res, char const **s, int *i, char c)
{
	size_t	len;
	size_t	k;

	len = strclen(*s, c);
	if (!len)
		return (0);
	res[*i] = (char *)malloc(sizeof(char) * (len + 1));
	if (res[*i] == NULL)
	{
		ppfree(res, *i);
		return (1);
	}
	k = 0;
	while (k < len)
	{
		res[*i][k] = **s;
		(*s)++;
		k++;
	}
	res[*i][k] = 0;
	(*i)++;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	if (s == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (num_of_words(s, c) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
			if (copier(res, &s, &i, c))
				return (NULL);
		if (*s != '\0')
			s++;
	}
	res[i] = NULL;
	return (res);
}
