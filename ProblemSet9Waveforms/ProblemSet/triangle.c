#include <stdio.h>
#include <math.h>
#include <sndfile.h>
#include <stdlib.h>
#include <string.h>

#define kNumChannels 1
#define kSampleRate 44100
#define kSec 1
#define kNumFrames (kSampleRate * kSec)
#define kFormat (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define kFileName "Triangle.wav"
#define kNumHarms 16

int main(){

  //file management
  SNDFILE *file;
  SF_INFO sfInfo;
  float *buffer;

  //Sine Wave Parameters
  float amplitude = 0.25f;
  float frequency = 440.0f;

  buffer = malloc(kNumChannels * kNumFrames * sizeof(float));
  if (buffer == NULL){
    printf("Cannot Allocate Buffer");
    return 1;
  }

  memset(&sfInfo, 0, sizeof(SF_INFO));

  sfInfo.samplerate = kSampleRate;
  sfInfo.channels = kNumChannels;
  sfInfo.frames = kNumFrames;
  sfInfo.format = kFormat;

  //Open File
  file = sf_open(kFileName, SFM_WRITE, &sfInfo);
  if(file == NULL){
    printf("404 Audio File Not Found");
    return 2;
  }

  // GENERATE SOUND

  for (int t = 0; t < kNumFrames; t++){
    for(int h = 1; h < kNumHarms; h++){
      float amp = amplitude;
      float phase = 0;
      //amp conditions
      if((h%2)==0){
        amp = 0;
      } else {
        amp = amplitude;
      }
      //phase conditions
      if( (h%10) == 3 || (h%10) == 3 ){
        phase = M_PI;
      } else {
        phase = 0;
      }
      float sample = (amp/pow(h,2)) * sin(2.0 * M_PI * ((frequency * h) / kSampleRate) * t + phase);
      for(int c = 0; c < kNumChannels; c++){//interleave audio (L/R are next to eachother per frame)
          buffer[kNumChannels * t + c] += sample;
      }
    }
  }

  //Write FILE
  sf_count_t count = sf_write_float(file, buffer, sfInfo.channels * kNumFrames);
  if(count != sfInfo.channels * kNumFrames){
      printf("Sample count Mismatch!");
      return 3;
    }

  //close audio file
  sf_close(file);
  return 0;
}
