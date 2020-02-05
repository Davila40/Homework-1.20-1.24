//Homework 1.23

#include <stdio.h>
#include <stdlib.h>
#include "files.h"

//int tabcheck(int j, int n);
//void fillLine(char line[], FILE* pfout, int limit);

int main(int argc, const char* argv[])
{
    FILE* fin;
    FILE* fout;
    int n;
    int ok = openfiles(argc, argv, &fin, &fout, &n);
    if(ok == 1)
    {
        printf("Error, Usage: ./1-23 input output");
        exit(1);
    }
    char c;
    int quote = 1;
    int charConstant = 1;
    int firstSlash = 1;
    int deleteLine = 1;
    int deleteSection = 1;
    int endSection = 1;
    while((c = fgetc(fin)) != EOF)
    {
      if(c == '\"' && charConstant == 1 && deleteLine == 1 && deleteSection == 1)
      {
        if(quote == 1)
        quote = 0;
        else
        quote = 1;
        firstSlash = 1;
      }
      else if(c == '\'' && quote == 1 && deleteLine == 1 && deleteSection == 1)
      {
        if(charConstant == 1)
        charConstant = 0;
        else
        charConstant = 1;
        firstSlash = 1;
      }
      else if(c == '/' && quote == 1 && charConstant == 1 && firstSlash == 1 && deleteLine == 1 && deleteSection == 1)
      {
        firstSlash = 0;
      }
      else if(c == '/' && quote == 1 && charConstant == 1 && firstSlash == 0)
      {
        deleteLine = 0;
        firstSlash = 1;
        fputc('\n', fout);
      }
      else if(c == '*' && quote == 1 && charConstant == 1 && firstSlash == 0)
      {
        deleteSection = 0;
        firstSlash = 1;
        fputc('\n', fout);
      }
      else if(c == '*' && deleteSection == 0)
      {
        endSection = 0;
      }
      if(deleteLine != 0 || deleteSection != 0)
      {
        fputc(c, fout);
      }
      else if(c == '\n' && deleteLine == 0)
      {
        deleteLine = 1;
        fputc(c, fout);
      }
      if(c == '/' && endSection == 0)
      {
        deleteSection = 1;
        endSection = 1;
      }
      else
      {
        endSection = 1;
      }
    }

    closefiles(fin, fout);
    return 0;
}
/*
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
*/
