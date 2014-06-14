#include <strings.h>
#include <stdio.h>
#include  <math.h>

#define SIZE 101

int max_path(int arr[SIZE][SIZE], int row, int col);

int
main()
{
	int	i, j;
	int	arr[SIZE][SIZE];
	int	val[SIZE][SIZE];

	bzero(arr, sizeof(arr));

	for (i = 1; i < SIZE; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	bzero(val, sizeof(val));
	i = SIZE - 1;
	for (j = 1; j < SIZE; j++) {
		val[i][j] = arr[i][j];
	}

	for (i = SIZE - 2; i >= 1; i--) {
		for (j = 1; j <= i; j++) {
			if (val[i + 1][j] >= val[i + 1][j + 1])
				val[i][j] = arr[i][j] + val[i+1][j];
			else
				val[i][j] = arr[i][j] + val[i+1][j+1];
		}
	}

	printf("%d\n", val[1][1]);

	return 0;
}

int
max_path(int arr[SIZE][SIZE], int row, int col)
{
	int	ltotal;
	int	rtotal;

	if (row > SIZE - 1)
		return 0;
	ltotal = max_path(arr, row+1, col);
	rtotal = max_path(arr, row+1, col+1);
	ltotal += arr[row][col];
	rtotal += arr[row][col];

	return ltotal > rtotal ? ltotal : rtotal;
}
