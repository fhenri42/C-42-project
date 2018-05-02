package main
import ("io/ioutil";"fmt")
func f(){ /*hello*/
var e="package main%cimport (%cio/ioutil%c;%cfmt%c)%cfunc f(){ /*hello*/%cvar e=%c%s%c%co := fmt.Sprintf(e,10,34,34,34,34,10,10,34,e,34,10,10,34,34,10,10,10,10,10);%cioutil.WriteFile(%cGrace_kid.go%c,[]byte(o), 0666);%c}%cfunc main(){%cf();%c}%c"
o := fmt.Sprintf(e,10,34,34,34,34,10,10,34,e,34,10,10,34,34,10,10,10,10,10);
ioutil.WriteFile("Grace_kid.go",[]byte(o), 0666);
}
func main(){
f();
}
