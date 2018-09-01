# include "../includes/malloc.h"

void                    *realloc_if_allocated(void *ptr, t_container *container, size_t blockSize, size_t size)
{
    int                 ptrPos;
    void                *tmp;

    if((ptrPos = get_ptr_pos_in_container(ptr, container)) != -1)
    {
        if(size > blockSize)
        {
            tmp = ft_memcpy(malloc(size), ptr, size);
            free_tiny_or_small(ptr);
            return tmp;
        };
        return ptr;
    }
    return NULL;
}

void                    *realloc(void *ptr, size_t size)
{
    int                 ptrPos;
    void                *tmp;

    ptrPos = 0;
    if(ptr == NULL)
        return malloc(size);
    if((ptrPos = is_large_ptr(ptr)) != -1)
    {
        if((size < g_env.large[ptrPos].length) & (size > SMALL))
            return ptr;
        tmp = malloc(size + 1);
        tmp = ft_memcpy(tmp, ptr, ft_strlen(ptr));
        free_large(ptrPos, ptr);
        return tmp;
    };
    if((ptr = realloc_if_allocated(ptr, g_env.tiny, TINY, size)) != NULL)
        return ptr;
    if((ptr = realloc_if_allocated(ptr, g_env.small, SMALL, size)) != NULL)
        return ptr;
    errno = ENOENT;
    return malloc(size);
}