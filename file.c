#include "main.h"

#define FILENAME "data.bin"

DataStruct data;

FILE *fptr;

int writeFile(char *stringToWrite) {
	int id = readFile(GET_DATA_AMOUNT, NULL);

	fptr = fopen(FILENAME, "ab");

	data.id = id;
	data.strlen = stringLen(stringToWrite);
	if (data.strlen >= STR_BUFFER) return -1;
	assignString(data.str, stringToWrite);

	fwrite(&data, sizeof(data), 1, fptr);

	fclose(fptr);

	return 0;
}

int readFile(int dataToRead, DataStruct *outputData) {
	if ((fptr = fopen(FILENAME, "rb")) == NULL) return FILE_OPENING_ERROR;

	int dataCounter = 0;

	while (fread(&data, sizeof(data), 1, fptr)) {
		dataCounter ++;

		if (dataCounter == dataToRead + 1) {
			assignString(outputData->str, data.str);
			outputData->strlen = data.strlen;
			break;
		}

		if (dataToRead == READ_ALL_DATA) {
			printf("%d: %s, %d;\n", data.id, data.str, data.strlen);
		}

	}

	fclose(fptr);
	return dataCounter;
}

