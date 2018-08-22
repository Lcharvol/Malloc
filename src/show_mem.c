
# include "../includes/prototypes.h"

void    print_blocks(t_container *container)
{
    int i;

    i = 0;
    while(i < BLOCKS_LENGTH)
    {
        ft_printf("%p\n", container + (i * BLOCKS_LENGTH));
        i++;
    }
}

void    print_container(t_container *container)
{
    while(container)
    {
        int i;

        i = 0;
        ft_putstr(container->containerName);
        ft_putstr(": ");
        ft_printf("%p\n", container);
        print_blocks(container);
        container = container->next;
    };
}

void show_alloc_mem() {
    t_env       *env = &s_env;

    if(env->tiny)
        print_container(env->tiny);
    else
        ft_putstr("TINY: NULL");
    ft_putchar('\n');
    if(env->small)
        print_container(env->small);
    else
        ft_putstr("SMALL: NULL");
    ft_putchar('\n');
    if(env->large)
        print_container(env->large);
    else
        ft_putstr("LARGE: NULL");
    ft_putchar('\n');
};