#include <stdio.h>
#define CAPACITY 20
#define NUM_OF_ITEMS 5

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack( int weights[], int values[], int selected_bool[] ) {
    
    int DP_arr[NUM_OF_ITEMS + 1][CAPACITY + 1];

    for (int i = 0; i <= NUM_OF_ITEMS; i++) {
        for (int w = 0; w <= CAPACITY; w++) {
            if (i == 0 || w == 0)  //no item/weight left
                DP_arr[i][w] = 0;
            else if (weights[i - 1] <= w) //if we have a place in the sack to this item
               DP_arr[i][w] = max(values[i - 1] + DP_arr[i - 1][w - weights[i - 1]], DP_arr[i - 1][w]); //should we take it?
            else
               DP_arr[i][w] = DP_arr[i - 1][w]; //ignore, not relevant
        }
    }

    int res = DP_arr[NUM_OF_ITEMS][CAPACITY];
    int w = CAPACITY;
    for (int i = NUM_OF_ITEMS ; i > 0 && res > 0 ; i--) {
        if (res == DP_arr[i-1][w]) //we didnt take this item
            continue;         
        else {                //we took --> update
            selected_bool[i - 1] = 1; 
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }
    
    return DP_arr[NUM_OF_ITEMS][CAPACITY];
}


int main() {
   char items[NUM_OF_ITEMS];
   int values[NUM_OF_ITEMS];
   int weights[NUM_OF_ITEMS];
   int selected_bool[NUM_OF_ITEMS]={0,0,0,0,0};

   //Enter the data;

   for (int i = 0; i < NUM_OF_ITEMS; i++) {
   
      printf("Enter name of item %d: ", i + 1);
      scanf("%c", &items[i]);
      printf("Enter value of item %d: ", i + 1);
      scanf("%d", &values[i]);
      printf("Enter weight of item %d: ", i + 1);
      scanf("%d", &weights[i]);
      getchar();
    }


   // print results
    int maxProfit = knapSack( weights, values, selected_bool);
    printf("Maximum profit: %d\n", maxProfit);
    printf("Selected items:");
    for (int i=0 ; i<NUM_OF_ITEMS; i++)
   {
      if (selected_bool[i]==1)
      printf(" %c", items[i]);
   }

    return 0;
}
