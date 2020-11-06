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

void unsigned_int(int nbr)
{
    if (nbr < 0){
        write(2,"ERROR NEGATIF NUMBER ON AN UNSIGNED INT FUNCTION\n",50);
        return(84);
    } else
        my_put_nbr(nbr);
        
}

int getmalloc(int nbr)
{
    int i = 0;

    for (i = 0; nbr != 1; nbr = nbr / 10, i++);
    return (i);
}

void hexadecimal_lower(int nbr)
{
    int *tab = malloc(getmalloc(nbr) * sizeof(int));
    char *alphab = "abcdef";
    char *rep = malloc (getmalloc(nbr) * sizeof(char));
    int i = 0;

    for (i = 0; nbr > 0; i++, nbr = nbr / 16)
        tab[i] = nbr % 16;
    for (int v = 0; v != i; v++){
        if (tab[v] > 10){
            rep[v] = alphab[tab[v] % 10];
        } else
            rep[v] = tab[v] + 48;
    }
    my_putstr(my_revstr(rep));
}

void hexadecimal_upper(int nbr)
{
    int *tab = malloc(nbr * sizeof(int));
    char *alphab = "ABCDEF";
    char *rep = malloc (nbr * sizeof(char));
    int i = 0;

    for (i = 0; nbr > 0; i++ , nbr = nbr / 16)
        tab[i] = nbr % 16;
    for (int v = 0; v != i; v++){
        if (tab[v] > 10){
            rep[v] = alphab[tab[v] % 10];
        } else
            rep[v] = tab[v] + 48;
    }
    my_putstr(my_revstr(rep));

}
