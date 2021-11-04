#include <stdio.h>
#include <math.h>

int main(){

  FILE *file;
  file = fopen("sin.csv", "w"); //open file
  if(file == NULL){
      printf("ERROR CODE 404 File not found or cannot be opened,");
  }

    float degs, rat, rads;

    for (degs = 0; degs < 2160; degs++){

      rads = degs * (M_PI/180);
      //get value of y
      rat = sin(rads)/rads;

      if (degs == 0){
        rat = 1;
      }
      //print to file
      fprintf(file, "%.2f, %.2f \n", degs, rat);
    }

    fclose(file);

  return 0;
}
