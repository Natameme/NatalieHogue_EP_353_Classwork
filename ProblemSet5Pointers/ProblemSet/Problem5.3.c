#include<stdio.h>
#include<stdlib.h>

/*///////CURRENT BUGS://///////
segmentation fault 11 being produced from copyString function, even though products are as desired.
*//////////////////////////////

//copyString prototype
void copyString(char *str1, char *str2);

//main function
int main(){

// 2 string variables
    char str1, str2;

// fill string 1 with user input
    system("clear");
    printf("Input a string: ");
    scanf("%[^\n]", &str1);

// copy string 1 to string 2
    copyString(&str1, &str2);

// print string 1 for debugging
    printf("String 1: %s \n", &str1);

// print string 2
    printf("String 2: %s \n", &str2);

//end of program
    return 0;
}

// copyString Function
void copyString(char *str1, char *str2){

// set string 2 equal to string 1
// use of a while loop copying string character for character eliminates incongruencies
  int i = 0;
  while(i != '\0'){
    str2[i] = str1[i];
    i++;
  }

/////////////////////////////////
/*///////////////////////////////
    *str2 = *str1; //deprecated solution, produces duplicate of first character

     ex. `String 1: Hello World
          String 2: HHello world`
*////////////////////////////////
/////////////////////////////////
}
