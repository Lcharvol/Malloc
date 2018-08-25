#include "./includes/prototypes.h"

int main() {

    // TINY 1
    char *str1 = (char *)malloc(10);
    ft_printf("str: %s \n", str1);
    int i = 0;

    while( i < 10) {
        str1[i] = 'T';
        i++;
    }
    str1[i] = '\0';

    // // TINY 2
    // char *str3 = (char *)malloc(5);
    // i = 0;

    // while( i < 5) {
    //     str3[i] = 'T';
    //     i++;
    // }
    // str3[i] = '\0';

    // //SMALL

    // char *str2 = (char *)malloc(50);
    // i = 0;

    // while( i < 50) {
    //     str2[i] = 'S';
    //     i++;
    // }
    // str2[i] = '\0';

    // //LARGE

    // char *str3 = (char *)malloc(4096);
    // i = 0;

    // while( i < 4096) {
    //     str3[i] = 'S';
    //     i++;
    // }
    // str3[i] = '\0';

    // SHOW ALLOCATE MEMORY
    // ft_printf("str2: %s \n", str2);
    // ft_printf("str3: %s \n", str3);
    show_alloc_content();
    return 0;
}