#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sndfile.h>

//Compile this code using:
//clang 02.ReadWriteAudioFile.c -o ReadWriteAudioFile -lsndfile

int main(void) {
  SNDFILE *inFile = NULL, *outFile = NULL; //pointers to a sound files
  SF_INFO sfInfo; //hold an information about a sound file
  const int bufferSize = 4096;
  float buffer[bufferSize]; //Buffer for holding samples

  //Initialize SF_INFO with 0s (memset is in string.h library)
  memset(&sfInfo, 0, sizeof(SF_INFO));

  //Open the original sound file as read mode
  inFile = sf_open("sine.wav", SFM_READ, &sfInfo);
  if(!inFile){
    printf ("Error : could not open file : sine.wav\n");
    puts (sf_strerror (NULL));
    return 1;
  }

  //Check if the file format is in good shape
  if(!sf_format_check(&sfInfo)){
    sf_close(inFile);
    printf("Invalid encoding\n");
    return 1;
  }

  //Copy samples from the original file to the new file
  sf_count_t readCount;

  while((readCount = sf_read_float(inFile, buffer, bufferSize)) > 0){
      for(int i=0; i<bufferSize; i++){
        printf("%f", buffer[i]);
      }
      printf("\n");
      sf_write_float(outfile, buffer, readCount);
  }


  //Open another sound file in write mode
  outFile = sf_open("CopiedSine.wav", SFM_WRITE, &sfInfo);

  //Check if the file was succefully opened
  if(!outFile){
    printf ("Error : could not open file : CopiedSine.wav");
    puts (sf_strerror(NULL));
    return 1;
  }

  //Write samples to a new file
  sf_write_float(outFile, buffer, readCount);

  //Close the open files
  sf_close(inFile);
  sf_close(outFile);

  return 0;
}
