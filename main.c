#include "main.h"

int main(int argc, char *argv[]) {
	if (argc < 3) {
		return 1;
	}
	createNewDatabase("testi");

	/*
	char *command = argv[1];
	char *filename = argv[2];

	if (stringComp(command, "write") == 0) {
		switch (writeFile(argv[3], filename)) {
			case TOO_LONG_INPUT:
				print("Liian pitkä syöte!");
				break;

			case NO_DATABASE_FOUND:
				print("Tietokantaa ei löytynyt!");
				break;
		}

	}
	else if (stringComp(command, "read") == 0) {
		if (argc < 3 || (stringComp(filename, "all") == 0)) {
			int dataCount;
			if ((dataCount = readFile(READ_ALL_DATA, NULL, filename)) == FILE_OPENING_ERROR) {
				print("Tiedostoa ei voitu avata!\n");
			}
			else {
				printf("\nKokonaismäärä: %d\n", dataCount);
			}
			
		}
		else {
			DataStruct output;
			int dataNum = strToInt(argv[3]);
			if (readFile(dataNum, &output, filename) == FILE_OPENING_ERROR) {
				print("Tiedostoa ei voitu avata!\n");
				return -1;
			}
			printf("%s\n", output.str);
		}
	}*/
	return 0;
}
