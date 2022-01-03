#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <string.h>
//#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
    char *arg = argv[argc-1];
    size_t len = strlen(arg);
    printf("%zu %s\n", len, arg);
    //getch();
}
