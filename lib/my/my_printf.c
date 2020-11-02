/*
** EPITECH PROJECT, 2020
** printf
** File description:
** my_printf
*/
#include <stdarg.h>

int my_strlen(char *str){
    int i = 0;
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

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
        tab[1] = count - 1;
    else
        tab[1] = count;
    return (tab);
}


void prints(char *str)
{
    int *tab = malloc (2 * sizeof(int));

    for (int i = 0; i != my_strlen(str); i++){
        if (str[i] <= 32 || str[i] >= 127){
            tab = convert(str[i]);
            my_putchar('\\');
                for (int v = 0; v != tab[1], tab[0] < 100; v++)
                    my_putchar('0');
                my_put_nbr(tab[0]);
        } else
            my_putchar(str[i]);
        }
}


void printnbr(int nbr){

    if (nbr == 0)
        my_putchar('0');
    else if (nbr < 0){
        my_putchar('-');
        my_put_nbr(nbr * -1);
    } else
        my_put_nbr(nbr);
}

void affiche(char str, va_list ap)
{
    char *valeur;
    char caract;
    int valeurd;

    switch (str){
        case 's':
            valeur = va_arg(ap, char *);
            my_putstr(valeur);
            break;
        case 'd':
            valeurd = va_arg(ap, int);
            printnbr(valeurd);
            break;
        case 'c':
            caract = va_arg(ap, char);
            my_putchar(caract);
            break;
        case 'S':
            valeur = va_arg(ap, char*);
            prints(valeur);
            break;
        case 'b':
            valeur = va_arg(ap, int);
            binary(valeur);
            break;     
    }
}

char *my_printf(char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    char *tab = malloc(my_strlen(str) * sizeof(char *));
    int index = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '%' && i != my_strlen(str) - 1){
            affiche(str[i + 1], ap);
            i++;
        }else{
            my_putchar(str[i]);
        }
    }
}
