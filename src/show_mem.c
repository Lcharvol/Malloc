
# include "../includes/prototypes.h"

void    print_blocks(t_container *container)
{
    int i;
    int blockSize;
    int isIn;
    int start;

    i = 0;
    isIn = 0;
    blockSize = ft_strcmp(container->containerName, "TINY") == 0 ? TINY : SMALL; 
    while(i < BLOCKS_LENGTH)
    {
        if(container->blocks[i] == 2)
        {
            isIn = isIn == 0 ? 1 : 0;
            if(isIn == 1)
            {
                start = i;
                ft_printf("%p - ", container + (i * blockSize));
            }
            else
            {
                ft_printf("%p : %d ", container + (i * blockSize), i - start + 1);
                ft_printf("octets\n");
            };
        };
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
        ft_putstr("TINY : NULL");
    ft_putchar('\n');
    if(env->small)
        print_container(env->small);
    else
        ft_putstr("SMALL : NULL");
    ft_putchar('\n');
    if(env->large)
        print_container(env->large);
    else
        ft_putstr("LARGE : NULL");
    ft_putchar('\n');
};