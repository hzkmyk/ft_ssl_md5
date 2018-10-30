#include "libft.h"

void	ft_uintdel(u_int32_t **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}