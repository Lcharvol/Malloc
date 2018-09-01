/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:57:39 by lcharvol          #+#    #+#             */
/*   Updated: 2018/09/01 18:07:05 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		print_blocks_mem(t_container *container)
{
	int		i;
	int		block_size;

	i = 0;
	block_size = ft_strcmp(container->name, "TINY") == 0 ? TINY : SMALL;
	while (i < BLOCKS_LENGTH)
	{
		if (container->blocks[i] != 0)
		{
			ft_printf(" %p \e[02m- \e[0m", (void *)container + (i * block_size)
					+ sizeof(t_container));
			ft_printf("%p : \e[32m %d octets \e[00m\n", (void *)container + (i
						* TINY) + sizeof(t_container) + block_size, block_size);
		}
		i++;
	}
}

void		print_container_mem(t_container *container)
{
	while (container)
	{
		ft_printf("\n\e[35m%s : \e[0m%p\n\n", container->name, container);
		print_blocks_mem(container);
		container = container->next;
	}
}

void		print_large_mem(t_large *large)
{
	while (large)
	{
		ft_printf("\n\e[35mLARGE\e[0m: %p\n\n", large);
		ft_printf(" %p \e[02m- \e[0m", (void *)large + sizeof(t_large));
		ft_printf("%p : \e[32m%d octets \e[00m\n", (void *)large +
				sizeof(t_large) + large->length, large->length);
		large = large->next;
	}
}

void		show_alloc_mem(void)
{
	t_env	*env;

	env = &g_env;
	if (env->tiny)
		print_container_mem(env->tiny);
	else
		ft_putstr("\n\e[35mTINY\e[0m : NULL\n");
	if (env->small)
		print_container_mem(env->small);
	else
		ft_putstr("\n\e[35mSMALL\e[0m : NULL\n");
	if (env->large)
		print_large_mem(env->large);
	else
		ft_putstr("\n\e[35mLARGE\e[0m : NULL\n");
	print_alloc_summ(env);
}
