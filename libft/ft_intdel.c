#include "libft.h"

void	ft_intdel(int **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}