#include <stdio.h>
#include <math.h>
int main(){

  float input, rads, degs;

  printf("Enter a value in Radians (pi is implicit): ");
  scanf("%f", &input );
  rads = input * M_PI;
  degs = rads * (180/M_PI);

  printf("%.2fπ radians is equal to %.2f degrees", rads, degs);

  return 0;
}
