//Homework 1.21

#include <stdio.h>
#include <stdlib.h>
#include "files.h"

int tabcheck(int j, int n);

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
    int i; // number of spaces
    int k; // counter
    int j = 0; // tab position
    while((c = fgetc(fin)) != EOF)
    {
      if(c != ' ')
      {
        fputc(c, fout);
        j = tabcheck(j, n);
        if(c == '\n')
        {
          j = 0;
        }
      }
      else
      {
        i = 1;
        while((c = fgetc(fin)) == ' ')
        {
          ++i;
        }
        for(k = n - j; k <= i; k = k + n)
        {
          fputc('\t', fout);
          j = 0;
        }
        if(j == 0)
        {
          i = i - k + n;
        }
        for(k = 1; k <= i; ++k)
        {
          fputc(' ', fout);
          j = tabcheck(j, n);
        }
        if(c == EOF)
        {
          break;
        }
        else
        {
          fputc(c, fout);
          j = tabcheck(j, n);
          if(c == '\n')
          {
            j = 0;
          }
        }
      }
    }

    closefiles(fin, fout);
    return 0;
}

int tabcheck(int j, int n)
{
  if(j >= n)
  return 1;
  return ++j;
}
