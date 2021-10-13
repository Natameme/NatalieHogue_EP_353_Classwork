#include<stdio.h>
#include<stdlib.h>

int main(){
  float arr[] = {0.1f, 0.9f, 0.3f, 0.8f, 0.6f};
  //get array size
  int arrSize = sizeof(arr) / sizeof(float) - 1;
  float *pa = arr;
  for(int i = 0; i <= arrSize; i++){
    printf("index: %i, value: %.1f\n", i, *( pa + i ) ); 
  }

  return 0;
}
