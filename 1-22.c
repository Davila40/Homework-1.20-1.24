//Homework 1.22

#include <stdio.h>
#include <stdlib.h>
#include "files.h"

int tabcheck(int j, int n);
void fillLine(char line[], FILE* pfout, int limit);

int main(int argc, const char* argv[])
{
    FILE* fin;
    FILE* fout;
    int n;
    int ok = openfiles(argc, argv, &fin, &fout, &n);
    if(ok == 1)
    {
        printf("Error, Usage: ./1-22 input output n");
        exit(1);
    }
    char c;
    char line[1000];
    int i = 0;
    int lastempty = 0;
    int newline = 0;
    while((c = fgetc(fin)) != EOF)
    {
      ++i;
      if(i > n)
      {
        if(lastempty != 0)
        {
          fillLine(line, fout, lastempty - 1);
          i = 0;
          for(int k = lastempty; k < n; ++k)
          {
            line[i] = line[k];
            ++i;
          }
          line[i] = c;
          ++i;
        }
        else
        {
          fillLine(line, fout, n);
          fputc(c, fout);
          i = 1;
        }
      }
      else if(c == ' ' || c == '\t')
      {
        lastempty = i;
        line[i - 1] = c;
      }
      else if(c == '\n')
      {
        line[i - 1] = c;
        lastempty = 0;
        fillLine(line, fout, i - 1);
        i = 0;
      }
      else
      {
        line[i - 1] = c;
      }
    }
    fillLine(line, fout, i);

    closefiles(fin, fout);
    return 0;
}

int tabcheck(int j, int n)
{
  if(j >= n)
  return 1;
  return ++j;
}
void fillLine(char line[], FILE* pfout, int limit)
{
  for(int i = 0; i < limit; ++i)
  {
    fputc(line[i], pfout);
  }
  fputc('\n', pfout);
}
