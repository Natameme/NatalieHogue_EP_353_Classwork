#include <stdio.h>
//CONTROL FLOW
int main(){

  char midiNote = 127;
  // Print a message, if MIDI note is is between 0 and 127
  if(midiNote >= 0 && midiNote <= 127) {
    printf("The note value entered is valid.\n");
    printf("MIDI note value is %d.\n", midiNote);
  }
  else{
    printf("MIDI note is not valid\n");
  }


return 0;
}
