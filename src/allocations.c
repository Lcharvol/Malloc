/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:34:28 by lcharvol          #+#    #+#             */
/*   Updated: 2018/09/01 17:42:07 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			*allocate_tiny_and_small(t_container *container)
{
	int			i;
	int			block_size;
	t_container	*tmp;

	tmp = container;
	block_size = ft_strcmp("TINY", container->name) == 0 ? TINY : SMALL;
	while (container)
	{
		i = 0;
		while (i < BLOCKS_LENGTH)
		{
			if ((container->next == NULL) & (i == BLOCKS_LENGTH - 1))
				container->next = create_container(block_size
						* BLOCKS_LENGTH, container->name);
			if (container->blocks[i] == 0)
			{
				container->blocks[i] = 1;
				return ((void *)container + sizeof(t_container)
						+ (i * block_size));
			}
			i++;
		}
		container = container->next;
	}
	return (NULL);
}

void			*allocate_large(t_large *large, size_t size)
{
	t_large		*new_ptr;
	t_large		*tmp;

	tmp = large;
	while (large->next)
		large = large->next;
	new_ptr = create_large(size);
	large->next = new_ptr;
	return (tmp);
}
