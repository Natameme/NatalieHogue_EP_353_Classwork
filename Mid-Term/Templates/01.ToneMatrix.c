#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

void shuffle(int *array, size_t n);
unsigned int randomInt(int min, int max);
void saveMatrix(int *matrix, int rowSize);

// Functions to implement
void initFirstRow(int *matrix, int rowSize);
void generateMatrix(int *matrix, int rowSize);

int main(){

  // Ask the user to enter the size of tone row
  int rowSize;
  system("clear");
  printf("Enter Desired Size of Tone Tow: ");
  scanf("%i", &rowSize);

  // Allocate the memory space for the matrix using rowSize
  int *matrix;
  matrix = malloc(sizeof(int) * pow(rowSize, 2));

  if(matrix == NULL){
    printf("Memory allocation failed...\n");
    return 1;
  }

  // Initialize the first row (P0) in the matrix
  initFirstRow(matrix, rowSize);

  // Generate the rest of the matrix based on the first row
  generateMatrix(matrix, rowSize);

  // Save the matrix to the text file
  saveMatrix(matrix, rowSize);

  // BONUS: printf matrix into console
  for (int row = 0; row < rowSize; row++){

    for (int column = 0; column < rowSize; column++){
      
      printf("%d ", matrix[row * rowSize + column]);
    }
    printf("\n");
  }


  // Free the memory space allocated
  free(matrix);
  return 0;
}

void initFirstRow(int *matrix, int rowSize){
  int hi = rowSize-1; //used to prompt user of upper note bounds

  // Intialize the first row in the matrix
  system("clear");
  printf("Enter Values between 0 - %i: \n", hi);

  //Variables
  int i = 0; //for indexing of while loop
  int usrIn; // bucket for user input

  // while loop prompts user to enter values
  while(i < rowSize){

    int j = (i + 1);//i + 1 for use with printf below
    printf("enter value # %i : ", j);
    scanf("%i", &usrIn);//take user input

 /* for loop checks to see if value is between upper and
    lower bounds as well as if a value is already present
    in the list, making sure each value only occurs once */
    for(int k = 0; k < i; k++){

      //conditional logic
        if(usrIn == matrix[k]){
          //tests if note has already been entered into row
          printf("That note has already been used please enter another \n");
          printf("enter value # %i : ", j);
          scanf("%i", &usrIn);

        } else if (usrIn >= rowSize || usrIn < 0 ){
          //tests if value is within bounds
          printf("That note is outside the specified bounds, please enter another \n");
          printf("enter value # %i : ", j);
          scanf("%i", &usrIn);
        } else {/*do nothing*/}

    }//end of k loop

    //set active cell to equal user input bucket
    matrix[i] = usrIn;

  i++;
  }//end of i loop

}//end of initFirstRow function
////////////////////////////////////////////////////////////////////////////////
void generateMatrix(int *matrix, int rowSize){

  // Keep a reference to the root tone (First tone in P0)
  int tonic = matrix[0];

  // Fix the pitch class to make the first tone start from 0
  for (int i = 0; i < rowSize; i++){

    //subtract tonic from every value
    matrix[i] = matrix[i] - tonic;

      //loops negative values back around
      if(matrix[i] < 0){
          matrix[i] = matrix[i] + rowSize;
        } else {/*do nothing*/}

  }

  //Get the inversion of P0 and populate I0
  for (int i = 1; i < rowSize; i++){
  	  matrix[i * rowSize] = abs(rowSize-matrix[i]);
  }

  // Fill out the rest of transposition
  // Matrix Indexing Loop
  for (int row = 1; row < rowSize; row++)
  {
  	for (int column = 1; column < rowSize; column++)
  	{
      int i = (row * rowSize + column);
  	  matrix[i] = matrix[row*rowSize] + matrix[column];
      // bring values back below 11
      if (matrix[i] >= rowSize){
        matrix[i] = matrix[i] - rowSize;
      } else {/*do nothing*/}
  	} //end of column loop
  } // end of row loop

  // Add back the root tone to the matrix
  int MIDIroot = 69;
  system("clear");
  printf("Select a MIDI note number between 0 and 127: ");
  scanf("%i", &MIDIroot);

  //check if entered note is within bounds may implement as external function later
  if (MIDIroot >= 127 || MIDIroot < 0 ){

    //tests if value is within bounds
    printf("That note is outside the specified bounds, please enter another \n");
    printf("Select a MIDI note number between 0 and 127: ");
    scanf("%i", &MIDIroot);

  } else {

    //Matrix Indexing Loop
    for (int row = 0; row < rowSize; row++)
    {
    	for (int column = 0; column < rowSize; column++)
    	{
        int i = (row * rowSize + column);
        matrix[i] = matrix[i] + MIDIroot;

    	}//end of column loop

    }//end of row loop

  }//end of else statement

}//end of generateMatrix function


//-------------------- Utility Functions --------------------
void saveMatrix(int *matrix, int rowSize){
  FILE *file; // Keep a reference to a text file
  file = fopen("matrix.txt", "w"); // open a text file in the write mode

  if(file == NULL){ // Check if the file opened
    printf("matrix.txt file could not be opened...\n");
    return;
  }

  // Go through the matrix and write the values in the text file
  for(int r = 0; r < rowSize; r++){
    for(int c = 0; c < rowSize; c++){
      fprintf(file, "%d ", matrix[r * rowSize + c]);
    }
    fprintf(file, "\n");
  }

  fclose(file); // Close the text file
}

unsigned int randomInt(int min, int max){
  unsigned int randval;
  FILE *f;

  f = fopen("/dev/random", "r");
  fread(&randval, sizeof(randval), 1, f);
  fclose(f);

  return (randval % (max - min)) + min;
}

void shuffle(int *array, size_t n)
{
  if (n > 1)
  {
      size_t i;
      for (i = 0; i < n - 1; i++)
      {
        size_t j = i + randomInt(0, UINT_MAX) / (UINT_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
        printf("%i, ", array[i]);
      }
  }
}
