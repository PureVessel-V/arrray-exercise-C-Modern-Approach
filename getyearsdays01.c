#include<stdio.h>
int main() {
	int year, m;
	int isLeap(int year);
	int getYearDays(int year);
	int getsumDays(int year);
	int getyear1stday(int year);
	int getmonthdays(int year, int m);
	int getmonth1stday(int year, int m);
	void printyear(int year);
	printf("Input:");
	scanf_s("%d", &year);
	printf("\n");
	printyear(year);
}
//S1 data preparation
int isLeap(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int getYearDays(int year){
	return isLeap(year) ? 366 : 365;
}
int getsumDays(int year){
	int i, sum;
	sum = 0;
	if (year > 2000) {
		for (i = 2000; i < year; i++) {
			sum += getYearDays(i);
		}
	}
	else {
		for (i = year; i++; i < 2000) {
			sum += getYearDays(i);
		}
	}
	return sum;
}
int getyear1stday(int year) {
	if (year > 2000) {
		return (6 + getsumDays(year)) % 7;
	}
	else {
		return (-getsumDays(year) + 6) % 7;
	}
}
int getmonthdays(int year, int m) {
	switch (m) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return isLeap(year) ? 29 : 28;
	default:
		return 0;
	}
}
int getmonth1stday(int year, int m) {
	int i, sum;
	sum = 0;
	for (i = 1; i < m; i++) {
		sum += getmonthdays(year, i);
	}
	return (getyear1stday(year) + sum % 7) % 7;
}
//S2 print year
void printyear(int year){
	int i, j, k, cntweek;;
	cntweek = 1;
	for (i = 1; i <= 12; i++) {
		printf("******************Month:%d*******************\n\n", i);
		printf("%-5c", ' ');
		for (k = 0; k <7; k++) {
			printf("#%-6d", k);
		}
		printf("\n\n");
		printf("%-2d | ", cntweek);
		for (j = 1; j <= getmonthdays(year, i) + getmonth1stday(year, i); j++) {
			if (j <= getmonth1stday(year, i)) {
				printf("%-7c", ' ');
			}
			else if (j % 7 == 0) {
				cntweek++;
				printf("%-7d\n\n%-2d | ", j-getmonth1stday(year,i),cntweek);
			}
			else {
				printf("%-7d", j-getmonth1stday(year,i));
			}
		}
		printf("\n\n");
	}
}