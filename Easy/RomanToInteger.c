#include <stdio.h>
#include <string.h>

int romanToInt(char *s)
{
    char *dict[7][2] = {{"I","1"}, {"V","5"},{"X","10"},{"L","50"},{"C","100"},{"D","500"},{"M","1000"}};
    int sum = 0;
    for(int i=0; i<strlen(s); i++){
        for (int j=0;j<7;j++){
            if (s[i] == dict[j][0][0]){
                sum += atoi(dict[j][1]);
            }
        }
    }
    return sum;
}

int main(void){
    printf("%d\n", romanToInt("III"));  // Output: 3
}