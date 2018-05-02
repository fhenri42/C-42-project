clang -Wall -Wextra -Werror -o Colleen Colleen.c; ./Colleen > tmp_Colleen
diff tmp_Colleen Colleen.c

clang -Wall -Wextra -Werror -o Grace Grace.c; ./Grace
diff Grace.c Grace_kid.c

clang -Wall -Wextra -Werror  -o Sully Sully.c ; ./Sully
diff Sully.c Sully_5.c
diff Sully_5.c Sully_4.c
diff Sully_4.c Sully_3.c
diff Sully_3.c Sully_2.c
diff Sully_2.c Sully_1.c
diff Sully_1.c Sully_0.c

ls -la
