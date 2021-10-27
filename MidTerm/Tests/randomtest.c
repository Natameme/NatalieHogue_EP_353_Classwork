#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

  //seed
  int in = abs(*value);
  srand(*value);
  //random value
  int randval = rand() / maxStep;
  if (randval > size){
    randval= randval - maxStep;
  } else {
    value = &randval;
    printf("random value: %i\n", randval);
  }

  return 0;
}
