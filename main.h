#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#define STR_BUFFER 64

#define FILE_OPENING_ERROR 0
#define GET_DATA_AMOUNT -1
#define READ_ALL_DATA -2

typedef struct {
	int id;
	char str[STR_BUFFER];
	int strlen;
} DataStruct;

extern void print(char *string);
extern void input(char *string, int len);

extern int stringLen(char *string);
extern int stringComp(char *string1, char *string2);
extern int strToInt(char *string);
extern void assignString(char *dstString, char *srcString);

extern int writeFile(char *stringToWrite);
extern int readFile(int dataToRead, DataStruct *outputData);

#endif
