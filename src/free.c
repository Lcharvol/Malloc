# include "../includes/prototypes.h"

void    delete_ptr_in_container(int ptrPos, t_container *container)
{
    int i;
    int blockSize;
    t_container *tmp;

    i = 0;
    tmp = container;
    blockSize = ft_strcmp(container->containerName, "TINY") == 0 ? TINY : SMALL; 
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
};

void     free_tiny_or_small(void *ptr)
{
    int ptrPos;

    if((ptrPos = get_ptr_pos_in_container(ptr, s_env.tiny)) != -1)
        delete_ptr_in_container(ptrPos, s_env.tiny);
    else if((ptrPos = get_ptr_pos_in_container(ptr, s_env.small)) != -1)
        delete_ptr_in_container(ptrPos, s_env.small);
    s_env.tiny = free_empty_container(s_env.tiny);
    s_env.small = free_empty_container(s_env.small);
};

void    free_large(int pos, void *ptr)
{
    size_t  length;

    length = s_env.large[pos].length;
    if(pos == 0)
        s_env.large = s_env.large->next;
    else
        s_env.large[pos - 1].next = &s_env.large[pos + 1];
    munmap(ptr - sizeof(t_large), length + sizeof(t_large));
};

void    free(void *ptr)
{
    int largePos;

    ft_printf("FREE\n");
    if((largePos = is_large_ptr(ptr)) != -1)
        free_large(largePos, ptr);
    else
        free_tiny_or_small(ptr);
};