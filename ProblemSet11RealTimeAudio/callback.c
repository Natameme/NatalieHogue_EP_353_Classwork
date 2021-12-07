#include <stdio.h>

void callback();
void caller(void (*ptr)());

int main(){
  void (*ptr)() = &callback;
  caller(ptr);
  return 0;
}


void callback(){
  printf("I am callback function!!!\n");
}

void caller(void (*ptr)()){
  printf("I am the caller!!!\n");
  (*ptr)();
}
