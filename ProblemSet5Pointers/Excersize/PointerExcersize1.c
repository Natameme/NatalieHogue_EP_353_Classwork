#include<stdio.h>

void swap(int *a, int *b);
void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int x = 10, y = 20;
    swap(&x,&y);

    printf("%d %d\n", x, y);

    return 0;
}


/*pointers and variable equivalences are
simply the difference between creating an
equivalence between 2 function variables,
and actually passing in the memory address
of a given variable*/
