# include "../includes/prototypes.h"



void                    *realloc(void *ptr, size_t size)
{
    int ptrPos;

    ptrPos = 0;
    if(!ptr)
        return NULL;
    if((ptrPos = is_large_ptr(ptr)) != -1)
    {
        ft_printf("REALLOC IN LARGE");
    }
    else if((ptrPos = get_ptr_pos_in_container(ptr, s_env.tiny)) != -1)
    {
        ft_printf("REALLOC IN TINY");
    }
    else if((ptrPos = get_ptr_pos_in_container(ptr, s_env.small)) != -1)
    {
        ft_printf("REALLOC IN SMALL");
    };
    return NULL;
};