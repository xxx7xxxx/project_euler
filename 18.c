#include <strings.h>
#include <stdio.h>
#include  <math.h>

#define SIZE 16

int max_path(int arr[SIZE][SIZE], int row, int col);

int
main()
{
	int	res, i, j;
	int	arr[SIZE][SIZE];

	bzero(arr, sizeof(arr));

	for (i = 1; i < SIZE; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}



	res = max_path(arr, 1, 1);
	printf("%d\n", res);

	return 0;
}

int
max_path(int arr[SIZE][SIZE], int row, int col)
{
	int	ltotal;
	int	rtotal;

	if (row > 15)
		return 0;
	ltotal = max_path(arr, row+1, col);
	rtotal = max_path(arr, row+1, col+1);
	ltotal += arr[row][col];
	rtotal += arr[row][col];

	return ltotal > rtotal ? ltotal : rtotal;
}
