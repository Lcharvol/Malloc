# include "../includes/malloc.h"

void    delete_ptr_in_container(int ptrPos, t_container *container)
{
    int i;
    int blockSize;
    t_container *tmp;

    i = 0;
    tmp = container;
    blockSize = ft_strcmp(container->name, "TINY") == 0 ? TINY : SMALL; 
    while(container)
    {
        while(i < BLOCKS_LENGTH)
        {
            if(i == ptrPos)
                container->blocks[i % BLOCKS_LENGTH] = 0;
            i++;
        }
        container = container->next;
    };
    container = tmp;
}

void     free_tiny_or_small(void *ptr)
{
    int ptrPos;

    if((ptrPos = get_ptr_pos_in_container(ptr, g_env.tiny)) != -1)
        delete_ptr_in_container(ptrPos, g_env.tiny);
    else if((ptrPos = get_ptr_pos_in_container(ptr, g_env.small)) != -1)
        delete_ptr_in_container(ptrPos, g_env.small);
    else

    
        return;
    g_env.tiny = free_empty_container(g_env.tiny);
    g_env.small = free_empty_container(g_env.small);
}

void    free_large(int pos, void *ptr)
{
    size_t  length;

    length = g_env.large[pos].length;
    if(pos == 0)
        g_env.large = g_env.large->next;
    else
        g_env.large[pos - 1].next = &g_env.large[pos + 1];
    munmap(ptr - sizeof(t_large), length + sizeof(t_large));
}

void    free(void *ptr)
{
    int largePos;
    
    if((largePos = is_large_ptr(ptr)) != -1)
        free_large(largePos, ptr);
    else
        free_tiny_or_small(ptr);
}