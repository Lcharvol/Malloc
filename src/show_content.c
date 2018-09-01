/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:51:40 by lcharvol          #+#    #+#             */
/*   Updated: 2018/09/01 17:57:28 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		print_blocks_content(t_container *container)
{
	int		i;
	int		is_in;

	i = 0;
	is_in = 0;
	while (i < BLOCKS_LENGTH)
	{
		if (container->blocks[i] != 0)
			ft_printf("'%s'\n", container + i + 1);
		i++;
	}
}

void		print_container_content(t_container *container)
{
	int		i;

	while (container)
	{
		i = 0;
		ft_putstr(container->name);
		ft_putstr(": ");
		ft_printf("%p\n", container);
		print_blocks_content(container);
		container = container->next;
	}
}

void		print_large_content(t_large *large)
{
	while (large->next)
	{
		ft_printf("LARGE: %p\n%s\n", large, large + 1);
		large = large->next;
	}
	ft_printf("LARGE: %p\n%s\n", large, large + 1);
}

void		show_alloc_content(void)
{
	t_env	*env;

	env = &g_env;
	if (env->tiny)
		print_container_content(env->tiny);
	else
		ft_putstr("TINY : NULL");
	ft_putchar('\n');
	if (env->small)
		print_container_content(env->small);
	else
		ft_putstr("SMALL : NULL");
	ft_putchar('\n');
	if (env->large)
		print_large_content(env->large);
	else
		ft_putstr("LARGE : NULL");
	ft_putchar('\n');
}
