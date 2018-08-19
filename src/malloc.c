# include "../includes/malloc.h"

void    *malloc(size_t size) {
    size++;
    char *test = "test";
    return test;
}