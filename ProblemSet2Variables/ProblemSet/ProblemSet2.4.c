#include <stdio.h>
#include <math.h>
//MAIN FUNCTION
int main(){
signed char loudness = -70; //holds dB as a value from -120dB to 0dB
float dB = loudness;
float amp = pow(10,(dB/20)); //holds linear amplitude scaling as a value from 0 to 1

//dB TO AMP EQUATION (AMP=10^(dB/20))

//print values
printf("The Loudness of %0.0fdB is %0.7f.\n", dB, amp);

//END OF CODE
return 0;
}