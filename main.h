#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#define STR_BUFFER 64

typedef struct {
	char str[STR_BUFFER];
	int strlen;
} DataStruct;

extern int stringlen(char *string);
extern int stringcomp(char *string1, char *string2);
extern int strToInt(char *string);
extern void assignString(char *dstString, char *srcString);

extern int writeFile(char *stringToWrite);
extern int readFile(int dataToRead, DataStruct *outputData);

#endif
