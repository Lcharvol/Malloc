# include "../includes/prototypes.h"

void    *allocate_new_block(t_page *page, int size)
{
    int i;

    i = 0;
    return mmap(0, size + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
};