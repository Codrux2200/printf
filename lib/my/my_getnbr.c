/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** desc
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);

char *cleaner(char *str)
{
    char *newstr = malloc(sizeof(char) * my_len(str));
    int i = 0;
    int b = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 48  && str[i] <= 57) {
            newstr[b] = str[i];
            b++;
        }
        i++;
    }
    return (newstr);
}

int puissance(char *str)
{
    int n = my_len(cleaner(str));
    int b = 1;
    int i = 0;
    while (i < n-1)
    {
        b = b *10;
        i++;
    }
    return (b);
}

int my_getnbr(char *str)
{
    int n = puissance(str);
    int negative = 0;
    int result = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 48  && str[i] <= 57) {
            if (str[i-1] == 45)
                negative = -1;
            result = result + (str[i] - 48) * n;
            n = n / 10;
        }
        i++;
    }
    if (negative == -1)
        result = result * (-1);
    return (result);
}