all:
		flex limbaj.l
		yacc -dv limbaj.y
		gcc y.tab.c lex.yy.c -lfl
		./a.out program.txt