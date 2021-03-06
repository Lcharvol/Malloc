/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:37:40 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/11 00:36:57 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb < -9)
			ft_putnbr((nb / 10) * -1);
		ft_putnbr((nb % 10) * -1);
		return ;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar('0' + (nb % 10));
}
