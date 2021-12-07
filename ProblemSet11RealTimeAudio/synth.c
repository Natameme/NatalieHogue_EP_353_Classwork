#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <portaudio.h>
#include <sndfile.h>
#include <math.h>
//compile with || clang synth.c -o synth -lportaudio -lsndfile
//run with || ./synth

#define kAudioInputDeviceIndex 0 //Built-in input
#define kAudioOutputDeviceIndex 1 //Built-in output
#define kNumFramesPerBuffer 512
#define kSamplingRate 44100.0
#define kNumChannels 2
#define kMIDIInputDeviceID 1
#define kMaxMIDIEvents 1
#define kDefaultFrequency 440.0f

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
void process(outBuffer, numFrames, void *userData);

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
  outputParameters.channelCount = sndFile.info.channels;
  outputParameters.device = kDeviceIndex;
  outputParameters.sampleFormat = paFloat32;
  outputParameters.suggestedLatency = 0.0f;

  SineWave sineWave;
  sineWave.frequency = kDefaultFrequency / kSampleRate;
  sineWave.phase = 0;
  sineWave.amplitude = 0.8f;

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
  unsigned long numFrames = frameCount *kNumChannels;
  process(outBuffer, numFrames, void *userData);
  return 0;
}

void process(float *buffer, unsigned long numFrames, void *userData){
  SineWave *sineWave = (SineWave *) userData;
  float theta = 0, sample = 0;

  for(unsigned long t = 0; t < numFrames; t += numFrames){
    theta = sineWave->phase * M_PI * 2.0f;
    sample = sin(theta);
    for(int c = 0; c < kNumChannels; c++){
        buffer[t + c] = sineWave->amplitude * sample;
    }
    //increment phase based on frequency
    sineWave->phase += sineWave->frequency;
    if(sineWave->phase >= 1.0f){
      sineWave->phase -= 1.0f;
    }

  }

}

int createOutputFile(SoundFile *file){
  memset(&file->info, 0, sizeof(SF_INFO));
  file->info.samplerate = kSampleRate;
  file->info.channels = kNumChannels;
  file->info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

  file->file = sf_open(kInputFileName, SFM_WRITE, &file->info);
return -1;
}
