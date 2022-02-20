

all:
	gcc -g -Wall Main_arvoreT_.c Funcs_arvoreT_.c H_arvoreT_.h my_string_.c my_string_.h -o ARV_T

run:
	./ARV_T

test:
	clear
	gcc -g -Wall Main_arvoreT_.c Funcs_arvoreT_.c H_arvoreT_.h my_string_.c my_string_.h -o ARV_T
	./ARV_T <4.in

val:
	clear
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./ARV_T <4.in