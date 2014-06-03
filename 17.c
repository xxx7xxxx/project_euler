#include <stdio.h>
#include <string.h>

#define HUNDREAD_LEN	7
#define AND_LEN		3

int
main(int argc, char *argv[])
{
	int 	total;
	int	bits_flag;
	int	units;
	int	tens;
	int	hundreads;
	int	i;

	int	num_len[91] = {
		0, 3, 3, 5, 4, 4, 3, 5, 5, 4,	/*needn't zero, so making num_len[0] = 0*/
		3, 6, 6, 8, 8, 7, 7, 9, 8, 8,
	};
	num_len[20] = 6;
	num_len[30] = 6;
	num_len[40] = 5;
	num_len[50] = 5;
	num_len[60] = 5;
	num_len[70] = 7;
	num_len[80] = 6;
	num_len[90] = 6;

	total = 0;
	for (i = 1; i <= 999; i++) {
		if (i / 100 != 0)
			bits_flag = 3;
		else if (i / 10 != 0)
			bits_flag = 2;
		else
			bits_flag = 1;

		switch (bits_flag) {
			case 1:
				total += num_len[i];
				break;
			case 2:
				if (i < 20) {
					total += num_len[i];
					break;
				}
				tens = i / 10;
				units = i % 10;
				total += num_len[tens * 10];
				if (units != 0)
					total+= num_len[units];
				break;
			case 3:
				hundreads = i / 100;
				tens = i % 100 / 10;
				units = i % 10;
				total += num_len[hundreads];
				total += HUNDREAD_LEN;

				if (i % 100 == 0)
					break;

				total += AND_LEN;
				if (i % 100 < 20) {
					total += num_len[i % 100];
					break;
				}

				total += num_len[tens * 10];
				total += num_len[units];
				break;
			default:
				fprintf(stderr, "something wrong\n");
				return -1;
				break;
		}
	}
	total += strlen("onethousand");
	printf("%d\n", total);

	return 0;
}
