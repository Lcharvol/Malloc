#include "./includes/prototypes.h"

int main() {
    int i = 0;
    // // TINY 1
    // char *str1 = (char *)malloc(16);

    // while( i < 16) {
    //     str1[i] = 'T';
    //     i++;
    // }
    // str1[i] = '\0';

    // // TINY 2
    // char *str2 = (char *)malloc(5);
    // i = 0;

    // while( i < 5) {
    //     str2[i] = 'T';
    //     i++;
    // }
    // str2[i] = '\0';

    // //SMALL 1

    // char *str3 = (char *)malloc(17);
    // i = 0;

    // while( i < 17) {
    //     str3[i] = 'S';
    //     i++;
    // }
    // str3[i] = '\0';

    // // LARGE 1

    // char *str4 = (char *)malloc(4097);
    // i = 0;

    // while( i < 4097) {
    //     str4[i] = 'L';
    //     i++;
    // }
    // str4[i] = '\0';

    // LARGE 2

    char *str5 = (char *)malloc(10000);
    i = 0;

    while( i < 10000) {
        str5[i] = 'B';
        i++;
    }
    str5[i] = '\0';

    // FREE

    // free(str4);
    // free(str5);
    // free(str1);
    // free(str2);
    // free(str3);

    // REALLOC

    // str1 = realloc(str1, 10000);
    // str2 = realloc(str2, 15000);
    // str3 = realloc(str3, 100);
    // str4 = realloc(str4, 0);
    str5 = realloc(str5, 400);

    // i = 0;
    // char *str6;
    // while(i < 200)
    // {
    //     str6 = (char *)malloc(10);
    //     str6[0] = 'w';
    //     str6[1] = '\0';
    //     i++;
    // }

    // SHOW ALLOCATE MEMORY

    show_alloc_content();

    // SHOW ALLOCATE CONTENT

    // show_alloc_content();

    return 0;
}
