#include <stdio.h>
#include <stdlib.h>
#include "files.h"

int openfiles(int argc, const char* argv[], FILE** pfin, FILE** pfout, int* n)
{
    if(argc != 3 && argc != 4)
    {
        return 1;
    }
    *pfin = fopen(argv[1], "r");
    *pfout = fopen(argv[2], "w");
    if(argc == 4)
    {
        *n = atoi(argv[3]);
    }
    else
        *n = 10;
    return 0;
}
void closefiles(FILE* pfin, FILE* pfout)
{
    fclose(pfin);
    fclose(pfout);
}
