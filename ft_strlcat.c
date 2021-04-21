/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:12:33 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/20 16:32:32 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	size_t	ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

size_t 	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	char	*dst_copy;
	char	*src_copy;
	size_t	dsize_copy;
	size_t	dlen;

	dst_copy = (char *)dst;
	src_copy = (char *)src;
	dsize_copy = dsize;
	while (dsize_copy-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - dst_copy;
	dsize_copy = dsize - dlen;
	if (dsize_copy-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (dsize_copy != 0)
		{
			*dst++ = *src;
			dsize_copy--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - src_copy));
}
