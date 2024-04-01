#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    char new[50];
    printf("Input the string: ");
    fgets(new, sizeof new, stdin);
    int i = 0;

    while(new[i]!='\0'){ // iterate thorugh until null char
     i++;       
    }

    printf("%d", i-1); // i-1 bc null character
}