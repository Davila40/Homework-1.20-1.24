#ifndef files_h
#define files_h
#include <stdio.h>
#include <stdlib.h>

int openfiles(int argc, const char* argv[], FILE** pfin, FILE** pfout, int* n);
void closefiles(FILE* pfin, FILE* pfout);
#endif /* files_h */
