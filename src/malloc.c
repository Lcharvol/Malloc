/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:04:59 by lcharvol          #+#    #+#             */
/*   Updated: 2018/09/01 16:12:30 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_env g_env = {NULL, NULL, NULL};

void	*get_large_ptr(t_large *large)
{
	while (large->next)
		large = large->next;
	return (large + sizeof(t_large));
}

int		get_strunc_length(t_large *container)
{
	int	length;

	length = 0;
	while (container)
	{
		length += 1;
		container = container->next;
	}
	return (length);
}

void	*malloc(size_t size)
{
	if (!size)
		return (NULL);
	if (size <= TINY)
	{
		if (!g_env.tiny)
			g_env.tiny = create_container(TINY * BLOCKS_LENGTH, "TINY");
		return (allocate_tiny_and_small(g_env.tiny));
	}
	if (size <= SMALL)
	{
		if (!g_env.small)
			g_env.small = create_container(SMALL * BLOCKS_LENGTH, "SMALL");
		return (allocate_tiny_and_small(g_env.small));
	}
	if (!g_env.large)
	{
		g_env.large = create_large(size);
		return (g_env.large + sizeof(t_large));
	}
	g_env.large = allocate_large(g_env.large, size);
	return (get_large_ptr(g_env.large));
}
