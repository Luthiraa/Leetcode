#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *defangIPaddr(char *address);

int main(void){
    char address[50];
    printf("Enter address: ");
    fgets(address, sizeof address, stdin);
    char *defanged = defangIPaddr(address);
    printf("%s ", defanged);
    free(defanged); 
    return 0;
}

char *defangIPaddr(char *address){
    char *defanged = malloc(50 * sizeof(char));
    int j = 0;
    for (int i = 0; i < (int)strlen(address); i++){
        if (address[i] != '.'){
            defanged[j] = address[i];
            j++;
        }
        else{
            defanged[j] = '[';
            defanged[j + 1] = '.';
            defanged[j + 2] = ']';
            j += 3;
        }
    }
    defanged[j] = '\0';
    return defanged;
}