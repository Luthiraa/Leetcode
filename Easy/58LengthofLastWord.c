#include <stdio.h>
#include <stdlib.h>

int lengthOfLastWord(char* s) {
    int length = 0;
    int tempLength = 0;
    for (int i=0; i<strlen(s); i++){
        if(s[i]==' '){
            if(tempLength != 0){
                length = tempLength;
            }
            tempLength = 0;
        }else{
            tempLength+=1;
        }
    }
    if(tempLength != 0){
        length = tempLength;
    }
    return length;  
}

int main(void){
    printf("%d ", lengthOfLastWord("Hello World"));
}
