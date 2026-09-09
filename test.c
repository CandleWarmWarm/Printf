#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("---\n");
	ft_printf("NULL %s NULL",NULL);
	printf("\n---\n");
	printf("NULL %s NULL",NULL);
	printf("\n---\n");
	return (0);
}