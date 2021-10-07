#include <stdio.h>

int main(){
  int size = 10;
  int nums[] = {1, 5, 6, 10, 3, 20, 7, 12, 17, 9};

  float sum = 0;


  for(int i; i < 10; i++){
    sum += nums[i];
  }

  float avg = sum / 10;

  printf("The Sum of the Set is: %f\n", sum);
  printf("The Average of the Set is %f\n", avg);
}
