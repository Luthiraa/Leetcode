#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

int main (void){
    char new[50];
    printf("Input the string: \n");
    fgets(new, sizeof new, stdin);
    puts(new);
}