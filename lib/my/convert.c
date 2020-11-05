/*
** EPITECH PROJECT, 2020
** convert
** File description:
** convert
*/
#include "my.h"

int *convert(char c)
{
    int *tab = malloc (2 * sizeof(int));
    int i = 0;
    int count = 3;

    for (int s = 0, v = 0; v != c; v++){
        if (s == 7){
            s = 0;
            count --;
            i += 3;
        } else {
            i++;
            s++;
        }
    }
    tab[0] = i;
    if (i < 9)
        tab[1] = 2;
    else
        tab[1] = 1;
    return (tab);
}


void octal(int nbr)
{
    char *result = malloc(10 * sizeof(char *));
    for (int v = 0; nbr != 0; v++){
        result[v] = (nbr % 8) + 48;
        nbr = nbr / 8;
    }
    my_putstr(my_revstr(result));
}

void choose(int nbr)
{
    if (nbr > 0)
        return (nbr);
    else
        return (nbr * -1);
}
