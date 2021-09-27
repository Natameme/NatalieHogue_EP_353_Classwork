#include <stdio.h>

int main(){
int midi = 98;

switch(midi){
//this feels really clunky and hard to read/edit but its what the prof did 
  case 96:
  case 97:
  case 98:
  case 99:
  case 100:
  case 101:
  case 102:
  case 103:
  case 104:
  case 105:
  case 106:
  case 107:
  case 108:

    printf("the MIDI note is %i\n", midi);
    break;

  default:
    printf("Whoa! That MIDI note is outside the specified range\n");
}
return 0;
}
