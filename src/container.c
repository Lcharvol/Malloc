# include "../includes/prototypes.h"

t_container   *create_container(size_t length, char *name)
{
    t_container  *newContainer;
    int     i;

    i = 0;
    t_block newArray[100];
    length = ((length + sizeof(t_container) + sizeof(t_block) - 1) / getpagesize()) *
	getpagesize() + getpagesize();
    newContainer = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    newContainer->blocks = ft_memcpy(&newContainer->blocks, &newArray, BLOCKS_LENGTH);
    newContainer->containerName = name;
    newContainer->length = length - sizeof(t_container);
    newContainer->next = NULL;
    return newContainer;
};

t_container  *create_large(void)
{
    t_container  *newContainer;
    newContainer = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    return newContainer;
}