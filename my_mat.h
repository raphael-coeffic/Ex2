#ifndef _MY_MAT_H_
#define _MY_MAT_H_

#define SIZE 10
#define INFINITY (10*10*10*10) 
#define TRUE 1
#define FALSE 0

void floyd_warshall(int matrix[][SIZE], int my_floyd_matrix[][SIZE]);
void functionA_init();
void functionB_boolHavePath(int i, int j);
void functionC_shortestPath(int i, int j);

extern char A, B, C, D;

#endif

