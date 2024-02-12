#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main() {
    while (1) {
        char func_choice = 0;
        int i, j;

        scanf(" %c", &func_choice);

        switch (func_choice) {
            case 'A':             // first function
                functionA_init();
                // printf("\n");
                break;

            case 'B':             // second function
                scanf("%d %d", &i, &j);
                functionB_boolHavePath(i, j);
                // printf("\n");
                break;

            case 'C':             // third function
                scanf("%d %d", &i, &j);
                functionC_shortestPath(i, j);
                // printf("\n");
                break;

            case 'D':             // exit
                // printf("\n");
                exit(0);

            // default:
            //                       // Invalid choice
            //     break;
        }
    }

    return 0;
}
