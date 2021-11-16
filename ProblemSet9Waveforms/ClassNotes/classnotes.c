#include <stdio.h>
#include <math.h>
#include <sndfile.h>
int main(){

  //SNDFILE* sf_open(const char *file, int mode, SF_INFO *sfinfo);
/*  Modes:
  - SFM_READ
  - SFM_WRITE
  - SFM_READWRITE
  */

  //SINE FUNCTION

  float degrees, radians, ratio;
  //file management
  FILE *file;
  file = fopen("sinewave.csv", "w"); //open file
  if(file == NULL){
      printf("ERROR CODE 404 File not found or cannot be opened,");
  }

  //variables
  for(int degrees = 0; degrees < 360; degrees++){
    //deg to rad
    radians = degrees * (M_PI / 180);

    //sin function
    ratio = sin(radians);

    printf("The sine of %.2d degrees is %.2f\n", degrees, ratio);
    fprintf(file, "%d, %f\n", degrees, ratio);
  }


//FORMULA FOR WAVE GENERATION

//  y = Amp * sin(2 * pi * freq * time + phase);

  fclose(file); //close file

  return 0;
}
