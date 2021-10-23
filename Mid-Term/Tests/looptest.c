#include <stdio.h>
#include <math.h>

int main(){

int rowSize = 12;


for (int row = 0; row < rowSize; row++)
{
  for (int column = 0; column < rowSize; column++)
  {
    printf("%i\n", (row * rowSize + column));
  }
}


return 0;
}
