#include "libft.h"

void    ft_fdintdel(int ***ap)
{
    int i;
    int **tmp;

    i = 0;
    tmp = *ap;
    if (tmp && *tmp)
    {
        while(tmp[i])
            ft_intdel(&tmp[i]);
        free(tmp);
        tmp = NULL;
    }
}