#include <stdio.h>
#include <stdbool.h>
//OPERATORS
// symbol that operates on a value or variable

//TYPES
    //Assignment: used for assigning variables, ex: int x = 5 :
    //arithmetic: add + : subtract - : multiply * : divide / : modulo % :
    //logical operators are used for boolean logic: and &&: or ||: not ! :
    //comparison operators compare 2 operands: greater than < : less than > : Equal to == : Not equal to != :
    //compound assignment: add to += : subtract from -= : multiply by *= : divide by /= : modulo by %= :
    // increment ++ : decrement -- :
    //result++ equivalent to result += 1;
    //Cast Operators Convert one datatype to another 



//EXPRESSIONS
    //equations: any legal combination of symbols that represents a value
    //consists of at least one operand and can have one or more operatrors
    //exponents have to be accompolished by multiplication (x^2 == x*x)



int main(){

    int a, b, result; //create 3 integers
    a = b = true;     // set a and b to 1
        printf("for a = %i & b = %i\n", a, b);
    result = !a;
        printf("!a = %d\n", result);
    result = a&&b;
        printf("a&&b = %i\n", result);
    b = false;
        printf("for b = %i\n", b);
    result = a&&b;
        printf("a&&b = %i\n", result);
    return 0;

    bool result;
    a = 10;
    printf("a = %i\n", a);
    b = 11;
    printf("b = %i\n", b);
    result = a <= b;
}


//PROBLEMSET FOR NEXT WEEK
//Write a C program that prints out the quotient and remainder of a division 100/267