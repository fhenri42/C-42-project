go build Colleen.go; ./Colleen > tmp_Colleen
diff tmp_Colleen Colleen.go

go build Grace.go; ./Grace
diff Grace.go Grace_kid.go

go build Sully.go ; ./Sully
diff Sully.go Sully_5.go
diff Sully_5.go Sully_4.go
diff Sully_4.go Sully_3.go
diff Sully_3.go Sully_2.go
diff Sully_2.go Sully_1.go
diff Sully_1.go Sully_0.go

ls -la
