#include "my_mat.h"
#include <stdio.h>

int my_floyd_matrix[SIZE][SIZE];

int min(int a, int b){
    return (a < b) ? a : b;
}

void floyd_warshall(int matrix[][SIZE], int my_floyd_matrix[][SIZE]) {
    // init the floyd matrix like the matrix and with infinity
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (i == j) {
                my_floyd_matrix[i][j] = 0;
            } else if (matrix[i][j] == 0) {
                my_floyd_matrix[i][j] = INFINITY;
            } else {
                my_floyd_matrix[i][j] = matrix[i][j];
            }        
        }
    }

    // floyd warshall algo
    int k;
    for (k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                my_floyd_matrix[i][j] = min(my_floyd_matrix[i][j], my_floyd_matrix[i][k] + my_floyd_matrix[k][j]);
            }
        }
    }
}

//init the matrix by the user
void functionA_init() {
    int val = 0;
    int matrix[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &val);
            matrix[i][j] = val;
            if (i != j && matrix[i][j] == 0) {
                matrix[i][j] = INFINITY;
            }
        }
    }

    // we use on all the other function the floyd matrix with the distance
    floyd_warshall(matrix, my_floyd_matrix);
}

// check if we have a path from i to j
void functionB_boolHavePath(int i, int j) {
    int warshall = my_floyd_matrix[i][j];
    if (warshall == 0 || warshall == INFINITY) {
        printf("False\n");
    } else {
        printf("True\n");
    }
}

// print the distance between i and j
void functionC_shortestPath(int i, int j) {
    int warshall = my_floyd_matrix[i][j];
    if (warshall == 0 || warshall == INFINITY) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", warshall);
    }
}
