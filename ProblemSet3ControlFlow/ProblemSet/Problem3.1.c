#include <stdio.h>
#include <stdlib.h>//adds system commands
//MAIN FUNCTION
int main(){
  //variables
  char noteName;
  int pitchClass;
  //Program Initialize
  system("clear");//clear console
  printf("Enter a White-Key Musical Note: ");
  scanf("%c", &noteName);
  //Conditional Logic
  switch(noteName){
    case 'C':
    case 'c':
      pitchClass = 0;
      break;
    /*case 'C#':
    case 'Db':
      pitchClass = 1;
      break;*/
    case 'D':
    case 'd':
      pitchClass = 2;
      break;
    /*case 'D#':
    case 'Eb':
      pitchClass = 3;
      break;*/
    case 'E':
    case 'e':
      pitchClass = 4;
    case 'F':
    case 'f':
      pitchClass = 5;
      break;
    /*case 'F#':
    case 'Gb':
      pitchClass = 6;
      break;*/
    case 'G':
    case 'g':
      pitchClass = 7;
      break;
    /*case 'G#':
    case 'Ab':
      pitchClass = 8;
      break;*/
    case 'A':
    case 'a':
      pitchClass = 9;
      break;
    /*case 'A#':
    case 'Bb':
      pitchClass = 9;
      break;*/
    case 'B':
    case 'b':
      pitchClass = 11;
      break;
  }
    printf("A note \'%c\' translates to %i in pitch class. \n", noteName, pitchClass);
//EXIT PROGRAM
return 0;
}
