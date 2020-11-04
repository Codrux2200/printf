/*
** EPITECH PROJECT, 2020
** printf
** File description:
** my_printf
*/
#include <stdarg.h>
#include "my.h"

void prints(char *str)
{
    int *tab = malloc (2 * sizeof(int *));

    for (int i = 0; i != my_strlen(str); i++){
        if (str[i] <= 32 || str[i] >= 127){
            tab = convert(str[i]);
            my_putchar('\\');
            if (str[i] < 100){
                for (int v = 0; v != tab[1] ; v++)
                    my_putchar('0');
                my_put_nbr(tab[0]);
            }else
                my_put_nbr(177);
        } else
            my_putchar(str[i]);
    }
}

void binary(int nbr)
{
    char *bin = malloc(nbr * sizeof(char *));
    
    if (nbr < 0)
        nbr = nbr * -1;
    for (int i = 0; nbr != 0 ; i++){
        if (nbr % 2 == 0)
            bin[i] = '0';
        else
            bin[i] = '1';
        nbr = nbr / 2;
    } 
    bin = my_revstr(bin);
    my_putstr(bin);
}

void switch2(char str, va_list ap)
{
    switch(str){
        case'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'o':
            my_put_nbr(octal(va_arg(ap, int)));
            break;
        case 'u':
            my_put_nbr(choose(va_arg(ap, int)));
            break;
    }

}


void affiche(char str, va_list ap)
{
    switch (str){
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'c':
            my_putchar(va_arg(ap, char));
            break;
        case 'S':
            prints(va_arg(ap, char *));
            break;
        case 'b':
            binary(va_arg(ap, int));
            break;    
    }
    switch2(str,ap);
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