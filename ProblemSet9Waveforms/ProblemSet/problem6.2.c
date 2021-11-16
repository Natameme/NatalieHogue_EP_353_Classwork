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
#define kFileName "ADSine.wav"
#define kNumHarms 1

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
      float attk = (0.0f + (t - 0.0f) * ((1.0f - 0.0f) / ((kNumFrames * 0.1) - 0)));
      float dec =  (1.0f + (t - 0.0f) * ((0.0f - 1.0f) / ((kNumFrames/0.9) - 0)));
      float sample = (amplitude * attk) * sin(2.0 * M_PI * ((frequency) / kSampleRate) * t + 0);
      for(int c = 0; c < kNumChannels; c++){//interleave audio (L/R are next to eachother per frame)
          buffer[kNumChannels * t + c] += fabs(attk * dec);
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
