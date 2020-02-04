#include <stdio.h>
#include <stdlib.h>
#include "files.h"

int main(int argc, const char* argv[])
{
    FILE* fin;
    FILE* fout;
    int n;
    int ok = openfiles(argc, argv, &fin, &fout, &n);
    if(ok == 1)
    {
        printf("Error, Usage: ./detab input output n");
        exit(1);
    }
    char c;
    int i = 0;
    while((c = fgetc(fin)) != EOF)
    {
        if(c == '\t')
        {
            for(int k = i; k < n; ++k)
                fputc(' ', fout);
            i = 0;
        }
        else{
            fputc(c, fout);
            ++i;
        }
        if(c == '\n')
            i = 0;
        if(i == n)
            i = 0;
    }

    closefiles(fin, fout);
    return 0;
}
