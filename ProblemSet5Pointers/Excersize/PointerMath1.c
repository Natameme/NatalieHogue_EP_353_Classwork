#include<stdio.h>

int main(){
  int numbers[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int arrSize = sizeof(numbers)/sizeof(int)-1;
  int *p = numbers;
  int i = 0;
  while(i <= arrSize){
    printf("index: %i value: %i address %p\n", i, *p, p);
    p++;
    i++;
  }
return 0;
}
