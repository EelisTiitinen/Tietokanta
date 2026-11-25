#include "main.h"

#define DB_LIST_FILE "databases.bin"

DataStruct data;

FILE *fptr;

int checkDatabaseNames(char *dbName);

int writeFile(char *stringToWrite, char *filename) {
	int id = readFile(GET_DATA_AMOUNT, NULL, filename);

	if (stringComp(filename, DB_LIST_FILE) != 0 && checkDatabaseNames(filename) == NO_DATABASE_FOUND) {
		return NO_DATABASE_FOUND;
	}

	fptr = fopen(filename, "ab");

	data.id = id;
	data.strlen = stringLen(stringToWrite);
	if (data.strlen >= STR_BUFFER) return -1;
	assignString(data.str, stringToWrite);

	fwrite(&data, sizeof(data), 1, fptr);

	fclose(fptr);

	return 0;
}

int readFile(int dataToRead, DataStruct *outputData, char *filename) {
	if ((fptr = fopen(filename, "rb")) == NULL) return FILE_OPENING_ERROR;

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

void createNewDatabase(char *dbName) {
	writeFile(dbName, DB_LIST_FILE);
	fclose(fopen(dbName, "wb"));
}

int viewDatabases() {
	return readFile(READ_ALL_DATA, NULL, DB_LIST_FILE);
}

int checkDatabaseNames(char *dbName) {
	if ((fptr = fopen(DB_LIST_FILE, "rb")) == NULL) return FILE_OPENING_ERROR;

	int dbIndex = 0;

	while (fread(&data, sizeof(data), 1, fptr)) {
		if (stringComp(data.str, dbName) == 0) {
			fclose(fptr);
			return dbIndex;
		}
		dbIndex ++;
	}
	fclose(fptr);
	return NO_DATABASE_FOUND;
}









