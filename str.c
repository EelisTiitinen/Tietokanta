#include "main.h"

int strToInt(char *string) {
	int len = stringLen(string);
	int multiplier = 1;
	int result = 0;
	int temp;

	for (int i = len - 1; i >= 0; i --) {
		if (string[i] > '9' || string[i] < '0') continue;
		temp = string[i] - '0';
		result += temp * multiplier;
		multiplier *= 10;
	}
	return result;
}
