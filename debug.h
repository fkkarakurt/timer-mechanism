#include<stdio.h>

#define COLOR_DEFAULT "\033[0m"
#define COLOR_RED_BOLD "\033[1;31m"
#define COLOR_MAGENTA "\033[0;35m"

#define errorf(a...){fprintf(stderr, "%serror:%s ", COLOR_RED_BOLD, COLOR_DEFAULT);fprintf(stderr, a);fprintf(stderr, " %s(%s %s:%d)%s\n", COLOR_RED_BOLD, __FUNCTION__, __FILE__,__LINE__, COLOR_DEFAULT);fflush(stderr);}
#define debugf(a...){fprintf(stderr, "%sdebug:%s ", COLOR_MAGENTA, COLOR_DEFAULT);fprintf(stderr, a);fprintf(stderr, " %s(%s %s:%d)%s\n", COLOR_RED_BOLD, __FUNCTION__, __FILE__,__LINE__, COLOR_DEFAULT);fflush(stderr);}