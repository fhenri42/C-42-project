package main
import ("io/ioutil";"fmt";"bytes";"os/exec";"strings")
func f(){ /*hello*/
var buffer bytes.Buffer
var y = 5
n := fmt.Sprintf("%d",y)
buffer.WriteString("Sully_")
buffer.WriteString(n)
buffer.WriteString(".go")
x := fmt.Sprintf("%s",buffer.String())
if(y > 0){
y--
e := `package main
import ("io/ioutil";"fmt";"bytes";"os/exec";"strings")
func f(){ /*hello*/
var buffer bytes.Buffer

var y = %d
n := fmt.Sprintf("%c%c",y)
buffer.WriteString("Sully_")
buffer.WriteString(n)
buffer.WriteString(".go")
x := fmt.Sprintf("%c%c",buffer.String())
if(y > 0){
y--
e := %c%s%c
o := fmt.Sprintf(e,y,37,100,37,115,96,e,96);
ioutil.WriteFile(buffer.String(),[]byte(o), 0666);
exec.Command("go","build",x).Run()
s := strings.Split(buffer.String(), ".")
c := fmt.Sprint("./",s[0])
exec.Command(c).Run()
}
}
func main(){
f();
}
`
o := fmt.Sprintf(e,y,37,100,37,115,96,e,96);
ioutil.WriteFile(buffer.String(),[]byte(o), 0666);
exec.Command("go","build",x).Run()
s := strings.Split(buffer.String(), ".")
c := fmt.Sprint("./",s[0])
exec.Command(c).Run()
}
}
func main(){
f();
}
