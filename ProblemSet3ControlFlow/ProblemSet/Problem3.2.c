#include <stdio.h>

int main(){
  char i;
  for(i=11; i>=0; i--){
    switch(i){
      case 11:
        printf("C ");
        break;
      case 10:
        printf("Db ");
        break;
      case 9:
        printf("D ");
        break;
      case 8:
        printf("Eb ");
        break;
      case 7:
        printf("E ");
        break;
      case 6:
        printf("F ");
        break;
      case 5:
        printf("Gb ");
        break;
      case 4:
        printf("G ");
        break;
      case 3:
        printf("Ab ");
        break;
      case 2:
        printf("A ");
        break;
      case 1:
        printf("Bb ");
        break;
      case 0:
        printf("B ");
        break;
    }
  }
  printf("\n");
//EXIT PROGRAM
return 0;
}
