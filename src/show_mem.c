
# include "../includes/prototypes.h"

void    print_blocks_mem(t_container *container)
{
    int i;
    int blockSize;
    int start;

    i = 0;
    blockSize = ft_strcmp(container->containerName, "TINY") == 0 ? TINY : SMALL; 
    while(i < BLOCKS_LENGTH)
    {
        if(container->blocks[i] != 0)
        {
            start = i;
            ft_printf(" %p - ", container + (i * blockSize) + sizeof(t_container));
            ft_printf("%p : %d octets\n", container + blockSize +
                (i * blockSize) + sizeof(t_container), blockSize);
        };
        i++;
    };
};

void    print_container_mem(t_container *container)
{
    while(container)
    {
        int i;

        i = 0;
        ft_putstr(container->containerName);
        ft_putstr(": ");
        ft_printf("%p\n", container);
        print_blocks_mem(container);
        container = container->next;
    };
};

void    print_large_mem(t_large *large)
{
    while(large->next)
    {
        ft_printf("LARGE: %p\n", large);
        ft_printf(" %p - ", large + sizeof(t_large));
        ft_printf(" %p : %d octets\n", large + sizeof(t_large) + large->length, large->length);
        large = large->next;
    };
    ft_printf("LARGE: %p\n", large);
    ft_printf(" %p - ", large + sizeof(t_large));
    ft_printf(" %p : %d octets\n", large + sizeof(t_large) + large->length, large->length);
};

void show_alloc_mem() {
    t_env       *env = &s_env;

    if(env->tiny)
        print_container_mem(env->tiny);
    else
        ft_putstr("TINY : NULL");
    ft_putchar('\n');
    if(env->small)
        print_container_mem(env->small);
    else
        ft_putstr("SMALL : NULL");
    ft_putchar('\n');
    if(env->large)
        print_large_mem(env->large);
    else
        ft_putstr("LARGE : NULL");
    ft_putchar('\n');
};