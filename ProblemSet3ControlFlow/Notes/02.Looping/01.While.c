/* A C program that shows examples of while and do-while loop statements. 

To compile and run this program, type:
clang 1.While.c -o 1.While && ./1.While
*/

#include <stdio.h>

int main() {  
  int midiNote = 64;

  // while loop that increments MIDI note until note value 77 is reached
  while (midiNote <= 76) {
    printf("MIDI note is %d\n",midiNote);
    midiNote++;
  }
  
  return 0;
}