#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

//define constants
#define kInputFileName "Sine.wav"
#define kOutputFileName "SineOut.wav"

typedef struct SoundFile
{
    SNDFILE *file;
    SF_INFO info;
} SoundFile;

//Function Prototypes
int OpenInputSndFile(SoundFile *inFile);
int createOutputSndFile(SoundFile *inFile, SoundFile *outFile);
void process (float *inBuffer, float *outBuffer, sf_count_t bufferSize);

  int main(){
    SoundFile inFile, outFile;

    //open input FILE
    int error = OpenInputSndFile(&inFile);
    if(error) return 1;

    sf_count_t bufferSize = inFile.info.frames;

    //allocate buffers for sound processing
    float *inBuffer = malloc(bufferSize * sizeof(float));
    float *outBuffer = malloc(bufferSize * sizeof(float));

    //copy file contents to buffers
    sf_read_float(inFile.file, inBuffer, bufferSize);

    // Process inBuffer & copy result to outBuffer

    process(inBuffer, outBuffer, bufferSize);

    //create output file
    error = createOutputSndFile(&inFile, &outFile);
    if(error) return 1;
    sf_write_float(outFile.file, outBuffer, bufferSize);

    //clean up
    sf_close(inFile.file);
    sf_close(outFile.file);
    free(inBuffer);
    free(outBuffer);
    return 0;
  }

  int OpenInputSndFile(SoundFile *file){
      //Initialize SF_INFO

      memset(&file->info, 0, sizeof(SF_INFO));

      // Open Original Sound File in Read model
      inFile->file = sf_open(kInputFileName, SFM_READ, &sndFile->info);
      if(sndFile->FILE == NULL){
        printf("ERROR: cannot open input file....");
        return 1;
      }

      //check File Format and Number of channels
      if(sndFile->info.channels > 1){
        printf("ERROR: File not mono");
        return 1;
      }

      //file info (samplerate, channels, duration, etc)


      return 0;
  }

  int createOutputSndFile(SoundFile *inFile, SoundFile *outFile){
    // Open another Sound file in write
    outFile->file = sf_open (kOutputFileName, SFM_WRITE, &inFile->info);
    if(outFile == NULL){
      printf("ERROR: Output File not found...");
      return 1;
    }

    return 0;
  }
  void process (float *inBuffer, float *outBuffer, sf_count_t bufferSize);
