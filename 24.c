#include <road.h>

#define N 10

int factor(int n)
{
	int	i;
	int	ans;
	ans = 1;
	for (i = 2; i <= n; i++)
		ans *= i;
	return ans;
}

int main()
{
	int	ans[N] = {0};
	int	restore[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	bit, i, j, m, k, remain;

	remain = 1000000 - 1;

	for (bit = 0; bit < N; bit++) {
		m = factor(N - bit - 1);
		i = remain / m;
		remain -= i * m;

		for (j = 0, k = -1; j < N; j++) {
			if (restore[j] != -1) {
				k++;
			}
			if (k == i)
				break;
		}
		ans[bit] = restore[j];
		restore[j] = -1;
		if (i == 0)
			break;
	}

	for (j = 0; j < N; j++) {
		if (restore[j] != -1)
			ans[bit++] = restore[j];
	}

	for (i = 0; i < N; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}


