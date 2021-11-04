#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//--For sndfile.h to work on your machine, install libsndfile via brew:
//brew intall libsndfile
//--or follow the instructions here to install libsndfile: https://github.com/erikd/libsndfile
#include <sndfile.h>

//--Compile this code using:
//clang 1.AudioFileInfo.c -lsndfile -o AudioFileInfo

//--After comppiling, run the program with:
//./AudioFileInfo yourSoundFileName.wav

int main() {

  SNDFILE *sndFile = NULL; //a sndfile pointer to a sound file
	SF_INFO sfInfo; //hold an information about a sound file

  memset(&sfInfo, 0, sizeof(SF_INFO)); //Initialize SF_INFO with 0s

  //Open the sound file as read only
  sndFile = sf_open("wave.wav", SFM_READ, &sfInfo);

  if(!sndFile){ //Exit the program if we failed to open the file
    printf("The sound file %s does not exist or cannot be opened\n", "sine.wav");
		exit(2);
	}

  //print out information about opened sound file
  printf("Sample rate for this file is %d\n", sfInfo.samplerate);
	printf("A number of channels in this file is %d\n", sfInfo.channels);
  printf("A number of frames in this file is %lld\n", sfInfo.frames);
  printf("time is %f\n", (double)sfInfo.frames / sfInfo.samplerate);

  if(sndFile){ //Close the sound file after done using
		sf_close(sndFile);
		sndFile = NULL;
	}

	return 0;
}
