# include "../includes/prototypes.h"



void     free_tiny_or_small(void *ptr)
{
    int ptrPos;

    if((ptrPos = get_ptr_pos_in_container(ptr, s_env.tiny)) != -1) {
        ft_printf("FIND TINY AT %d POS\n", ptrPos);
    }
    else{
        ptrPos = get_ptr_pos_in_container(ptr, s_env.small);
        ft_printf("FIND SMALL AT %d POS\n", ptrPos);
    }
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

    if((largePos = is_large_ptr(ptr)) != -1)
        free_large(largePos, ptr);
    else
        free_tiny_or_small(ptr);
};