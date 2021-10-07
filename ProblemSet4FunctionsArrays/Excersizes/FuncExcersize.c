#include <stdio.h>


int add(int, int);

// 2. Define the function so that we can call it
int add(int a, int b){
  return a + b;
}

void sum(int, int);

void sum(int a, int b){
  printf("The Sum is %i\n",add(a,b));
}

int main(){
int x = 420, y = 69;
int z;

sum(x,y);

return 0;

}
