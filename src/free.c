/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:13:01 by lcharvol          #+#    #+#             */
/*   Updated: 2018/09/01 16:20:11 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			delete_ptr_in_container(int ptr_pos, t_container *container)
{
	int			i;
	int			block_size;
	t_container	*tmp;

	i = 0;
	tmp = container;
	block_size = ft_strcmp(container->name, "TINY") == 0 ? TINY : SMALL;
	while (container)
	{
		while (i < BLOCKS_LENGTH)
		{
			if (i == ptr_pos)
				container->blocks[i % BLOCKS_LENGTH] = 0;
			i++;
		}
		container = container->next;
	}
	container = tmp;
}

void			free_tiny_or_small(void *ptr)
{
	int			ptr_pos;

	if ((ptr_pos = get_ptr_pos_in_container(ptr, g_env.tiny)) != -1)
		delete_ptr_in_container(ptr_pos, g_env.tiny);
	else if ((ptr_pos = get_ptr_pos_in_container(ptr, g_env.small)) != -1)
		delete_ptr_in_container(ptr_pos, g_env.small);
	else
		return ;
	g_env.tiny = free_empty_container(g_env.tiny);
	g_env.small = free_empty_container(g_env.small);
}

void			free_large(int pos, void *ptr)
{
	size_t		length;

	length = g_env.large[pos].length;
	if (pos == 0)
		g_env.large = g_env.large->next;
	else
		g_env.large[pos - 1].next = &g_env.large[pos + 1];
	munmap(ptr - sizeof(t_large), length + sizeof(t_large));
}

void			free(void *ptr)
{
	int			large_pos;

	if ((large_pos = is_large_ptr(ptr)) != -1)
		free_large(large_pos, ptr);
	else
		free_tiny_or_small(ptr);
}
