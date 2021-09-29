#include <stdio.h>
#include <stdlib.h>//adds system commands
//MAIN FUNCTION
int main(){
  char noteName;
  int pitchClass;
  system("clear");
  printf("Enter a White-Key Musical Note: ");
  scanf("%c", &noteName);
  switch(noteName){
    case 'C':
      pitchClass = 0;
      break;
    /*case 'C#':
    case 'Db':
      pitchClass = 1;
      break;*/
    case 'D':
      pitchClass = 2;
      break;
    /*case 'D#':
    case 'Eb':
      pitchClass = 3;
      break;*/
    case 'E':
      pitchClass = 4;
    case 'F':
      pitchClass = 5;
      break;
    /*case 'F#':
    case 'Gb':
      pitchClass = 6;
      break;*/
    case 'G':
      pitchClass = 7;
      break;
    /*case 'G#':
    case 'Ab':
      pitchClass = 8;
      break;*/
    case 'A':
      pitchClass = 9;
      break;
    /*case 'A#':
    case 'Bb':
      pitchClass = 9;
      break;*/
    case 'B':
      pitchClass = 11;
      break;
  }
    printf("A note \'%c\' translates to %i in pitch class. \n", noteName, pitchClass);
//EXIT PROGRAM
return 0;
}
