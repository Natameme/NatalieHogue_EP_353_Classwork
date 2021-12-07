#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <portaudio.h>
#include <sndfile.h>
//compile with || clang PA.c -o PA -lportaudio -lsndfile
//run with || ./PA

#define kInputFileName "Recording.wav"
#define kDeviceIndex 2
#define kNumFramePerBuffer 512
#define kSampleRate 44100
#define kNumChannels 2
#define kDefaultFrequency 440
//function prototypes
typedef struct SineWave{
  float frequency;
  float amplitude;
  float phase;
} SineWave;

int openInputFile(SoundFile *file);
int createOutputFile(SoundFile *file);
int initPortAudio();
int closePortAudio();
void printPaDevices();
int renderCallback(
  const void *input,
  void *output,
  unsigned long frameCount,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData //access to interior of callback function
);

int main(){
//open Port Audio
  if (initPortAudio()) return 1;
  //print devices
  printPaDevices();

//configure port audio streaming
  PaStream *pStream = NULL;
  PaStreamParameters outputParameters;
  SoundFile sndFile;
  createOutputFile(&sndFile);
  openInputFile(&sndFile);
  memset(&outputParameters, 0, sizeof(PaStreamParameters));
  ouputParameters.channelCount = sndFile.info.channels;
  ouputParameters.device = kDeviceIndex;
  ouputParameters.sampleFormat = paFloat32;
  ouputParameters.suggestedLatency = 0.0f;

  //Open PortAudio streaming
  PaError error = Pa_OpenStream(
    &pStream,
    &inputParameters,
    NULL,
    sndFile.info.samplerate,
    kNumFramePerBuffer,
    paNoFlag,
    renderCallback,
    &sndFile
  );
  if(error != paNoError){
    printf("Error, Pa_Open failed %s\n", Pa_GetErrorText(error));
    return 1;
  }

//start PA streaming audio
  error = Pa_StartStream(pStream);
  if(error != paNoError){
    printf("Error, Pa_StartStream failed %s\n", Pa_GetErrorText(error));
    return 1;
  } else {
    int wait = 0;
    printf("Hit Enter to end Playback: ");
    scanf("%d", &wait);
    //stop streaming
    error = Pa_StopStream(pStream);
    if(error != paNoError){
      printf("Error, Pa_StopStream failed %s\n", Pa_GetErrorText(error));
      return 1;
    }
  }

  sf_close(sndFile.file);
  //close Port Audio
  if (closePortAudio()) return 1;
//end of main function
  return 0;
}

/////////////
//FUNCTIONS//
/////////////
int initPortAudio(){
  PaError error;
  //init port Audio
  error = Pa_Initialize();
  //error management
  if(error != paNoError){
      printf("Error PA Init Failed with %s\n", Pa_GetErrorText(error));
      return 1;
  }
  printf("PortAudio Initialize Success!\n");
  return error;
}

int closePortAudio(){
  PaError error;
  //terminate port audio
  error = Pa_Terminate();
  if(error != paNoError){
      printf("Error PA Terminate Failed with %s", Pa_GetErrorText(error));
      return 1;
  }
  return error;
}

void printPaDevices(){
  //Get Audio Devices
  int numDevice;
  PaDeviceIndex curDeviceID;

  const PaDeviceInfo *pDeviceInfo;
  const PaHostApiInfo *pHostApiInfo;

  numDevice = Pa_GetDeviceCount();

  for(curDeviceID = 0; curDeviceID < numDevice; curDeviceID++){
    pDeviceInfo = Pa_GetDeviceInfo(curDeviceID);
    pHostApiInfo = Pa_GetHostApiInfo(pDeviceInfo ->hostApi);
    printf("-----------------------------------------------\n");
    printf("ID: %d, Name: %s ", curDeviceID, pDeviceInfo->name);
    printf("API name: %s\n", pHostApiInfo->name);
    printf("Max output channels: %d\n", pDeviceInfo->maxOutputChannels);
    printf("Max input channels: %d\n", pDeviceInfo->maxInputChannels);
  }
}

int openInputFile(SoundFile *file){
  memset(&file->info, 0, sizeof(SF_INFO));
  file->file = sf_open(kInputFileName, SFM_READ, &file->info);
  if(file->file == NULL){
    printf("Null File...");
    return 1;
  }
  return 0;
}

int renderCallback(
  const void *input,
  void *output,
  unsigned long frameCount,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData //access to interior of callback function
){
  float *inBuffer = (float *) input;
  float *outBuffer = (float *) output;
  unsigned long numFrames = frameCount * kNumChannels;
  for (unsigned long t = 0; t < numFrames; t += kNumChannels);
    for(int c = 0; c < kNumChannels; c++){
      outBuffer[t+c] = inBuffer[t+c];
    }
  return 0;
}

int createOutputFile(SoundFile *file){
  memset(&file->info, 0, sizeof(SF_INFO));
  file->info.samplerate = kSampleRate;
  file->info.channels = kNumChannels;
  file->info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

  file->file = sf_open(kInputFileName, SFM_WRITE, &file->info);
return -1;
}
