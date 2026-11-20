#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		return 1;
	}

	printf("%d", stringlen(argv[1]));
	/*
	if (stringcomp(argv[1], "write") == 0) {
		if (argc < 3) {
			printf("Tiedostoon ei voida kirjoittaa tyhjää!\n");
		}
		else if (writeFile(argv[2]) == -1) {
			printf("Liian pitkä syöte!\n");
		}
	}
	else if (stringcomp(argv[1], "read") == 0) {
		if (argc < 3 || (stringcomp(argv[2], "all") == 0)) {
			int dataCount = readFile(-1, NULL);
			if (dataCount == -1) {
				printf("Tiedostoa ei voitu avat!\n");
			}
			else {
				printf("\nKokonaismäärä: %d\n", dataCount);
			}
			
		}
		else {
			DataStruct output;
			int dataNum = strToInt(argv[2]);
			if (readFile(dataNum, &output) == -1) {
				printf("Tiedostoa ei voitu avata!\n");
				return -1;
			}
			printf("%s, %d\n", output.str, output.strlen);
		}
	}*/
	return 0;
}
