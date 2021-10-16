#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
  int x;
  int y;
} point;

typedef struct size
{
  int width;
  int height;
} size;

typedef struct rectangle
{
    point point;
    size size;
} rect;

int main(){
  rect tangle = {{1,4}{40,20}};

  printf("The base of the rectangle is at x: %i, y: %i with dimensions w: %i, h: %i", tangle.point.x, tangle.point.y, tangle.size.width, tangle.size.height);

  return 0;
}
