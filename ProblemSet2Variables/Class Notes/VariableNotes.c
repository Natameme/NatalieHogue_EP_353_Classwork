//standard Input Output
#include <stdio.h>

//MAIN FUNCTION
int main(){
	//Declare and initialize variables
	// type name = value;
    //Integers
	int number = 123;
    //Floating Point (Decimal) Number: 32bit/7 decimal place accuracy
	float z = 40.5f;
    //Double: Double Precision Float: 64bit/15 decimal place accuracy
	double pi = 3.0f;
    //Character
	char c = 'A';
    //String, Represented by char *
	char *str = "This is a String";

	//Print their values	
//		placeholders specify type and use %
//      \n is a line break
//      values for placeholders are specified after string
//      printf("integer: %i, float: %f, double: %d, character: %c, string: %s\n", int, float, double, char, string);
	printf("number: %d, pi: %f, z: %f, c: %c, str: %s\n", number,  pi, z, c, str);
	
	//Change values in each variable
	number = 420;
	z = 0.69f;
    pi = 3.14159265;
	c = 'B';
	str = "You're Really Still Reading This?";
	
	//Print their values	
	printf("number: %d, pi: %f, z: %f, c: %c, str: %s\n", number,  pi, z, c, str);

	printf("%c", '\n');
		
	return 0;
}
//C VARIABLE NAMING RULES
//can contain Letters and Numbers 
//No WhiteSpace or Commas
//no special symbols other than _
//should start with Letters
//cannot be called anything that means something else in C
//cAsE SeNsItIvE

//DATA TYPES
// different data types take up different data spaces within the compiled file

//PRIMARY DATA TYPES
//associated with the memory space they occupy
	//char   occupies 1 byte,  uses %c placeholder 
	//short  occupies 2 bytes, uses %d placeholder 
	//int    occupies 4 bytes, uses %d placeholder
	//long   occupies 8 bytes, uses %ld placeholder
	//float  occupues 4 bytes, uses %f placeholder
	//double occupies 8 bytes, uses %lf placeholder

//PRINTF
	//Based on ASCII table (American Standard Code for Information Interchange)
	//maps each character to an integer to allow encoding and decoding betweeen readable text and Binary
