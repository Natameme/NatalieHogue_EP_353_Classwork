#include <stdio.h>

int main(){
  int num;
  int sum = num + 12;
  printf("Please Type in an Integer");
  scanf("%i", &num);
  printf("Your Value: %i, plus 12 is %i\n",num, sum);

  return 0;
}
