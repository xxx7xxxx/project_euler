#include <string.h>
#include <stdio.h>

int main()
{
	int	i, j;
	int	sum;
	char	name[100];
	int	len;
	int	total;


	total = 0;
	for (i = 1; ; i++) {
		if (scanf("%s", name) <= 0)
			break;
		printf("%s\n", name);
		len = strlen(name);
		sum = 0;
		for (j = 0; j < len; j++) {
			sum += name[j] - 'A' + 1;
		}
		total += i * sum;
	}
	printf("%d\n", total);

	return 0;
}
