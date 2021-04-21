/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:15:35 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/20 20:02:59 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elm;

	elm = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (elm->next)
		elm = elm->next;
	elm->next = new;
}
