/*
** EPITECH PROJECT, 2020
** convert
** File description:
** convert
*/
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


int octal(int nbr)
{
    int i = 0;
    for (int s = 0, v = 0; v != nbr; v++){
        if (s == 7){
            s = 0;
            i += 3;
        } else {
            i++;
            s++;
        }
    }
    return (i);
}

void choose(int nbr){
    if (nbr > 0)
        return (nbr);
    else
        return (nbr * -1);
}
