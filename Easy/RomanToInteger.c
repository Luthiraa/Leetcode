#include <stdio.h>
#include <string.h>

int romanToInt(char *s)
{
    char *dict[7][2] = {{"I","1"}, {"V","5"},{"X","10"},{"L","50"},{"C","100"},{"D","500"},{"M","1000"}};
    int sum = 0;
    int i = 0;
    while (s[i]) {
        int value = 0;
        for (int j = 0; j < 7; j++) {
            if (s[i] == dict[j][0][0]) {
                value = atoi(dict[j][1]);
                break;
            }
        }
        if (s[i+1]) {
            int next_value = 0;
            for (int j = 0; j < 7; j++) {
                if (s[i+1] == dict[j][0][0]) {
                    next_value = atoi(dict[j][1]);
                    break;
                }
            }
            if (next_value > value) {
                sum += next_value - value;
                i++;
            } else {
                sum += value;
            }
        } else {
            sum += value;
        }
        i++;
    }
    return sum;
}

int main(void){
    printf("%d\n", romanToInt("III"));  // Output: 3
    printf("%d\n", romanToInt("MCMXCIV")); // Output: 1994
}