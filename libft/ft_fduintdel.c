#include "libft.h"

void    ft_fduintdel(u_int32_t ***ap)
{
    int i;
    u_int32_t **tmp;

    i = 0;
    tmp = *ap;
    if (tmp && *tmp)
    {
        while(tmp[i])
            ft_uintdel(&tmp[i]);
        free(tmp);
        tmp = NULL;
    }
}