#include <stdio.h>
#include <stdlib.h>


int main(){
  //2 dimensional array
  int matrix[12][12];
  int *matrix = calloc(144, sizeof(int));

  if (matrix == NULL){
    printf("Memory Allocation Failed....\n");
    return 1;
  }
free(matrix);
return 0;
}
