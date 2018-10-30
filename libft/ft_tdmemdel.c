#include "libft.h"

void    ft_tdmemdel(void ***ap)
{
    int i;
    void **tmp;

    i = 0;
    tmp = *ap;
    if (tmp && *tmp)
    {
        while(tmp[i])
            ft_memdel(&tmp[i]);
        free(tmp);
        tmp = NULL;
    }
}