/*
** ETNA PROJECT
** my_str_to_int
** File description:
**      [str to int]
*/

#include <stdio.h>

long long my_str_to_int(const char *str)
{
    int digit = 0;
    int signe = 0;
    int number = 0;    
    while (str[digit] < 48 || str[digit] > 57) {
        if (str[digit] == '-') {
            signe++;
        }
        digit++;
    }
    while (str[digit] > 47 && str[digit] < 58) {
        number = number + str[digit] - 48;
        
        if (str[digit + 1] > 47 && str[digit + 1] < 58) {
            number = number * 10;
        }
        digit++;
    }
    if (signe % 2 == 1) {
        number = - number;
    }
    return (number);
}
