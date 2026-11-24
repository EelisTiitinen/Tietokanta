#include "main.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		return 1;
	}

	if (stringComp(argv[1], "write") == 0) {
		if (argc < 3) {
			print("Tietokantaan ei voida kirjoittaa tyhjää!\n");
		}
		else if (writeFile(argv[2]) == -1) {
			print("Liian pitkä syöte!\n");
		}
	}
	else if (stringComp(argv[1], "read") == 0) {
		if (argc < 3 || (stringComp(argv[2], "all") == 0)) {
			int dataCount;
			if ((dataCount = readFile(READ_ALL_DATA, NULL)) == FILE_OPENING_ERROR) {
				print("Tiedostoa ei voitu avata!\n");
			}
			else {
				printf("\nKokonaismäärä: %d\n", dataCount);
			}
			
		}
		else {
			DataStruct output;
			int dataNum = strToInt(argv[2]);
			if (readFile(dataNum, &output) == FILE_OPENING_ERROR) {
				print("Tiedostoa ei voitu avata!\n");
				return -1;
			}
			printf("%s\n", output.str);
		}
	}
	return 0;
}
