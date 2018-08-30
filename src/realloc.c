# include "../includes/prototypes.h"

void                    *realloc_if_allocated(void *ptr, t_container *container, size_t blockSize, size_t size)
{
    int ptrPos;

    if((ptrPos = get_ptr_pos_in_container(ptr, container)) != -1)
    {
        if(size > blockSize)
        {
            free_tiny_or_small(ptr);
            return malloc(size);
        };
        return ptr;
    }
    return NULL;
};

void                    *realloc(void *ptr, size_t size)
{
    int ptrPos;

    ft_printf("REALLOC: %d\n", size);
    ptrPos = 0;
    if(!ptr)
        return malloc(size);
    if((ptrPos = is_large_ptr(ptr)) != -1)
    {
        if((size < s_env.large[ptrPos].length) & (size > SMALL))
            return ptr;
        free_large(ptrPos, ptr);
        return malloc(size);
    };
    if((ptr = realloc_if_allocated(ptr, s_env.tiny, TINY, size)) != NULL)
        return ptr;
    if((ptr = realloc_if_allocated(ptr, s_env.small, SMALL, size)) != NULL)
        return ptr;
    return NULL;
};