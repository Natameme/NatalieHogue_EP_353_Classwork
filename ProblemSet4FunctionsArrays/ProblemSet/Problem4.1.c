#include <stdio.h>

//Looping Function
void beatBox(int);
void beatBox(int bar){
  for(int i = 1; i <= bar; i++){
      if (i % 4 == 0){//every 4 bar
        printf("Potato Cats!\n\n");
      } else {
        printf("Boots N Cats N\n");//every bar that is not a multiple of 4
      }
    }
}

int main(){
  int bars;
  int beat;
  printf("How Many Bars Would You Like to Beatbox for? : ");
  scanf("%d", &bars);
  beatBox(bars);
  return 0;
}
