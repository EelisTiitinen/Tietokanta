#include "main.h"

#define FILENAME "data.bin"

DataStruct data;

FILE *fptr;

int writeFile(char *stringToWrite) {
	fptr = fopen(FILENAME, "ab");
	
	data.strlen = stringlenni(stringToWrite);
	if (data.strlen >= STR_BUFFER) return -1;
	assignString(data.str, stringToWrite);

	fwrite(&data, sizeof(data), 1, fptr);

	fclose(fptr);

	return 0;
}

int readFile(int dataToRead, DataStruct *outputData) {
	if ((fptr = fopen(FILENAME, "rb")) == NULL) return -1;

	int dataCounter = 0;

	while (fread(&data, sizeof(data), 1, fptr)) {
		dataCounter ++;
		if (dataCounter == dataToRead) {
			assignString(outputData->str, data.str);
			outputData->strlen = data.strlen;
			break;
		}

		if (dataToRead == -1) {
			printf("%s, %d;\n", data.str, data.strlen);
		}
	}

	fclose(fptr);
	return dataCounter;
}

