#include <stdio.h>

/*
 42 is love
*/

void myFunction(void) {
char *x="#include <stdio.h>%c%c/*%c 42 is love%c*/%c%cvoid myFunction(void) {%cchar *x=%c%s%c;%cprintf(x,10,10,10,10,10,10,10,34,x,34,10,10,10,10,10,10,10,10,10,10,10);%c}%c%cint main(void) {%c/*%c main function%c*/%cmyFunction();%creturn 0;%c}%c";
printf(x,10,10,10,10,10,10,10,34,x,34,10,10,10,10,10,10,10,10,10,10,10);
}

int main(void) {
/*
 main function
*/
myFunction();
return 0;
}
