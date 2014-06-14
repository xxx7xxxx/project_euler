#include <string.h>
#include <stdio.h>

int main()
{
	int	days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31,
				30, 31, 30, 31};
	int	year, month, day;
	int	days_m;
	int	sundays;
	int	counter;

	sundays = 0;
	counter = 0;
	for (year = 1900; year <= 2000; year++) {
		for (month = 1; month <= 12; month++) {
			days_m = days[month];
			if ( (year % 4 == 0 && year % 100 != 0) ||
					year % 400 == 0) {
				if (month == 2)
					days_m = 29;
				printf("%d\n", year);
			}
			for (day = 1; day <= days_m; day++) {
				counter++;
				if (counter % 7 == 0) {
					if (year != 1900 && day == 1)
						sundays++;
					counter = 0;
				}
			}
		}
	}
	printf("%d\n", sundays);

	return 0;
}
