#include "main.h"

int stringlenni(char *string) {
	int len = 0;
	for (len; string[len] != 0; len ++);
	return len;
}

int stringcomp(char *string1, char *string2) {
	for (int i = 0; string1[i] == string2[i]; i ++) {
		if (string1[i] == 0) return 0;
	}
	return -1;
}

int strToInt(char *string) {
	int len = stringlenni(string);
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

void assignString(char *dstString, char *srcString) {
	for (int i = 0; srcString[i] != 0; i ++) {
		dstString[i] = srcString[i];
	}
}

