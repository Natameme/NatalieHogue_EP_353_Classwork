#include<stdio.h>
#include<stdlib.h>

int main(){
  system("cd /Templates");
  system("clang 01.ToneMatrix.c -o ToneMatrix && clang 02.TraverseMatrix.c -o TraverseMatrix && clang 03.MappingToneMatrix.c -o MappingToneMatrix");
  system("./ToneMatrix");
  return 0;
}
