#include <stdio.h>

int main(){
  int numbers[] = {5,4,3,2,1};

  for(int i=0; i < 5; i++){
    printf("Index: %d Value: %d\n", i, numbers[i]);
  }
  return 0;
}
