#include <stdio.h>
//CONTROL FLOW
int main(){

  char midiNote = 127;
  // Print a message, if MIDI note is is out of range
  if(midiNote < 0 || midiNote > 127)
    printf("\nThe note value entered is Invalid.\n");

  //---------------------------------------------
  // 2. if-then statement with block
  // if (/* condition */) {
  //   /* execute this code in the block */
  // }

  // Print a message, if MIDI note is is between 0 and 127
  if(midiNote >= 0 && midiNote <= 127) {
    printf("The note value entered is valid.\n");
    printf("MIDI note value is %d.\n", midiNote);
  }


return 0;
}
