#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//compile with " clang 03.MappingToneMatrix.c -o MappingToneMatrix "

typedef struct Note {
  int pitch;
  int velocity;
  char *duration;
} Note;

void append2File(Note note);
int  getSize(char *fileName);
void readSeries(int *series, int size);

int main(){
  system("rm -f notes.txt"); // delete notes.txt if it exists

  // create a mapping table (array) for pitch, velocity, and duration
  // Must use the Note struct in this process.

  int rowSize = sqrt(getSize("matrix.txt"));

  Note toneRow[rowSize];
  // Check to make sure that the table size is at least
  // the size of row in the original matrix.

  // Count the number of sequence in the series.txt file
  int numSeries = getSize("series.txt");
  if(numSeries == 0){
    printf("The series.txt does not exist or the content is empty...\n");
    return 1;
  }

  // allocate enough memory space to hold all tone values in series.txt
  int *series = malloc(sizeof(int)*numSeries);
  if (series == NULL){
    printf("The series array does not have anything...\n");
    return 0;
  }

  // Read tone values and assign to the series array
  readSeries(series, numSeries);

  int  *vel = malloc(sizeof(int));
  char dur = '8';

  printf("\n\nEnter a MIDI Velocity for your tone row: ");
  scanf("%d", vel);

  // Map the series array to the mapping table
  for(int i = 0; i < numSeries; i++){
    toneRow[i].pitch = series[i];
    toneRow[i].velocity = *vel;
    toneRow[i].duration = &dur;
    append2File(toneRow[i]);
  }

  //renames notes.txt to melody.txt
    rename("notes.txt", "melody.txt");

  // free memory sapce
    free(series);
  return 0;
}

//-------------------- Utility Functions --------------------
int getSize(char *fileName){
  FILE *file;
  file = fopen(fileName, "r");

  if(file == NULL){
    printf("%s could not be opened...\n", fileName);
    return 0;
  }

  int value, count = 0;
  while(fscanf(file, "%d", &value) != EOF) count++;

  fclose(file);

  return count;
}

void readSeries(int *series, int size){
  FILE *file;
  file = fopen("series.txt", "r");

  if(file == NULL){
    printf("series.txt could not be opened...\n");
    return;
  }

  for (int i = 0; i < size * size; i++) {
    fscanf(file, "%d", &series[i]);
  }

  fclose(file);
}

void append2File(Note note){
  static unsigned int count = 0;
  FILE *file;
  file = fopen("notes.txt", "a");
  fprintf(file, "%d, %d %d %s;\n", count++, note.pitch, note.velocity, note.duration);
  fclose(file);
}
