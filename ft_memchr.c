/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:08:36 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/20 15:06:32 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//locate byte in byte string

void	*ft_memchr(const void *s, int c, size_t n)
{	
	char		f;

	f = c;
	while (n)
	{
		if (*(char *)s == f)
		{
			return ((void *)s);
		}
		s++;
		n--;
	}
	return (NULL);
}
