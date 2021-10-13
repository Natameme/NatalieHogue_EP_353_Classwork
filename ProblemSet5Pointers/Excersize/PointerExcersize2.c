#include<stdio.h>


int main(){

  int number;
  int *p = &number;

  printf("Pick a Number, Any Number: ");
  scanf("%i", &number);

  printf("\n\nnumber: %i &number: %p p: %p *p: %d", number, &number, p, *p);

  return 0;
}
