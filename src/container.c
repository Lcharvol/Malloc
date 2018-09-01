# include "../includes/prototypes.h"

t_container   *create_container(size_t length, char *name)
{
    t_container  *newContainer;
    int     i;
    i = 0;
    
    length = ((length + sizeof(t_container) - 1) /
        getpagesize()) * getpagesize() + getpagesize();
    if((newContainer = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
        return NULL;
    newContainer->name = name;
    newContainer->length = length - sizeof(t_container);
    newContainer->next = NULL;
    return newContainer;
};

t_large  *create_large(size_t length)
{
    t_large  *newLarge;

    length = ((length + sizeof(t_large) - 1) / getpagesize()) * getpagesize() + getpagesize();
    if((newLarge = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
        return NULL;
    newLarge->length = length - sizeof(t_large);
    newLarge->next = NULL;
    return newLarge;
}