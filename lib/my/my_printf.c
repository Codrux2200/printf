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
            if (valeurd == 0)
                my_putchar('0');
            else
                my_put_nbr(valeurd);
            break;
        case 'c':
            caract = va_arg(ap, char);
            my_putchar(caract);
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
