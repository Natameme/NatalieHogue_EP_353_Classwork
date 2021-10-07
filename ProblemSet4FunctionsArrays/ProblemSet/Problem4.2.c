#include <stdio.h>

//main array
int numbers[] = {5, 9, 1, 2, 4, 8, 3};

int main(){
  //get size of array
  int arrSize = sizeof(numbers)/ sizeof(int) - 1;

  //debugging: print Array
  for(int i=0; i <= arrSize; i++){
    printf("The value of arr at index %d is %d\n", i, numbers[i]);
  }

//flippydo
  printf("\n¡FlippityDo!\n\n");

/////////////////////////
// flip array 3rd attempt
// inspired by method at
// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
// no code lifted but the iterative method was followed
/////////////////////////

int bucket;//temporary holding place for values
int start = 0;//starting point
int end = arrSize;//ending point
while(start < end){
  bucket = numbers[start];
  numbers[start] = numbers[end];
  numbers[end] = bucket;
  start++;
  end--;
}

//print reversed array
  for(int i=0; i <= arrSize; i++){
    printf("The value of arr at index %d is %d\n", i, numbers[i]);
  }

//2 new lines
printf("\n\n");

//end program
return 0;
}

//DEPRECATED CODE
/*
//flip array
int j = 0;//placeholder for loop
  for(int i = arrSize; i >= j; i--){
      numbers[i] = numbers[j];
      printf("%d ::: %d \n",i, j);
      j++;
  }
*/

/*
//flip array 2nd attempt
for ((int i = 0) && (int j = arrSize); (i <= arrSize) && (j >= 0); (i++) && (j--))
{
    numbers[i] = numbers[j];
}
*/
