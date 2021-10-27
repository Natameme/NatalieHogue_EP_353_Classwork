#include <stdio.h>
#include <stdlib.h>

int main(){
  int rowSize = 0;//variable for size of row


  //get rowSize from user input
  printf("enter row size: ");
  scanf("%i", &rowSize);

  //initialize tone matrix of size rowSize^2
  int toneMatrix[rowSize][rowSize]; //2d array of size rowSize^2

  //pointers
  //int *matrix = toneMatrix;

  //fill matrix with 0s
  for(int i = 0; i < rowSize; i++){
    for(int j = 0; j < rowSize; j++){
      toneMatrix[j][i] = (i * j);
      //matrix[j][i] = (i * j);
    }
  }
  //print matrix
  for(int i = 0; i < rowSize; i++){
    for(int j = 0; j < rowSize; j++){
      printf("%i, ", toneMatrix[j][i]);
      //printf("%i, ", matrix[j][i])
    }
    printf("\n");
  }

  return 0;
}
