#include <stdio.h>
#include <stdlib.h>

int main(){

int arr;
int arrSize;

int *arrAlloc = malloc(sizeof(int)*arrSize);
if (arrAlloc == NULL) {
  fprintf(stderr, "malloc failed\n");
  return -1;
}

printf("Input Size of Array: ")
scanf("%i", &arrSize);
printf("\n");






  return 0;
}
