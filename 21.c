#include <strings.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int	i, j;
	int	total;
	int	sum;
	int	other_num;

	total = 0;
	for (i = 1; i < 10000; i++) {
		sum = 0;
		for (j = 1; j < i; j++) {
			if (i % j == 0)
				sum += j;
		}
		if (sum == i)
			continue;

		other_num = sum;
		sum = 0;
		for (j = 1; j < other_num; j++) {
			if (other_num % j == 0)
				sum += j;
		}
		if (sum == i)
			total += i;
	}

	printf("%d\n", total);

	return 0;
}
