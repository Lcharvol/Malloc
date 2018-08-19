# include "../includes/prototypes.h"

void    *malloc(size_t size) {
    size++;
    char *test = "test";
    return test;
}