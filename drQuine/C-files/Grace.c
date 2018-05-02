#include <stdio.h>
#define L
#define Func(void) int main() { FILE *fd = fopen("Grace_kid.c","w+"); char *x = "#include <stdio.h>%c#define L%c#define Func(void) int main() { FILE *fd = fopen(%cGrace_kid.c%c,%cw+%c); char *x = %c%s%c; fprintf(fd, x, 10, 10, 34, 34, 34, 34, 34, x, 34, 10, 10, 10, 10, 10); }%c/*%c 42 is love%c*/%cFunc(void)%c"; fprintf(fd, x, 10, 10, 34, 34, 34, 34, 34, x, 34, 10, 10, 10, 10, 10); }
/*
 42 is love
*/
Func(void)
