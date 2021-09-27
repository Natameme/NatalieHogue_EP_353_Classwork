#include <stdio.h>

int main(){
  int i = 0;
  int j = 0;
  for (int i=0; i<11; i++){
    printf("-------------\n");
    for(int j=0; j<11; j++){
      if(j>=i){
        printf("%i %i\n", j, i);
      }
    }
  }
return 0;
}
