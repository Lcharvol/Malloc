/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:57:01 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/11 17:15:58 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
