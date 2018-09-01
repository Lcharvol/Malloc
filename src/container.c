/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:43:03 by lcharvol          #+#    #+#             */
/*   Updated: 2018/09/01 17:47:32 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_container		*create_container(size_t length, char *name)
{
	t_container	*new_container;
	int			i;

	i = 0;
	length = ((length + sizeof(t_container) - 1) /
			getpagesize()) * getpagesize() + getpagesize();
	if ((new_container = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON
					| MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	new_container->name = name;
	new_container->length = length - sizeof(t_container);
	new_container->next = NULL;
	return (new_container);
}

t_large			*create_large(size_t length)
{
	t_large		*new_large;

	length = ((length + sizeof(t_large) - 1) / getpagesize())
		* getpagesize() + getpagesize();
	if ((new_large = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON
					| MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	new_large->length = length - sizeof(t_large);
	new_large->next = NULL;
	return (new_large);
}
