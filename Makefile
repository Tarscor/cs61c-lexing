Flags=-Wall -g -std=c99
<<<<<<< HEAD


61ccc : main.o tokenizer.o tokenizer-errors.o tokens.o string-helpers.o utils.o preprocessor.o
	gcc $(Flags) -o 61ccc main.o tokenizer.o tokenizer-errors.o tokens.o string-helpers.o utils.o preprocessor.o

main.o : main.c tokens.h tokenizer.h preprocessor.h
	gcc $(Flags) -c main.c

tokens.o : tokens.c tokens.h
	gcc $(Flags) -c tokens.c

tokenizer.o : tokenizer.c string-helpers.h utils.h tokenizer.h tokens.h preprocessor.h tokenizer-errors.h
	gcc $(Flags) -c tokenizer.c

tokenizer-errors.o : tokenizer-errors.c tokenizer-errors.h utils.h tokens.h string-helpers.h
	gcc $(Flags) -c tokenizer-errors.c

string-helpers.o: string-helpers.c string-helpers.h
	gcc $(Flags) -c string-helpers.c

utils.o: utils.c utils.h
	gcc $(Flags) -c utils.c

preprocessor.o: preprocessor.c preprocessor.h string-helpers.h
	gcc $(Flags) -c preprocessor.c

clean:
	rm -f *.o
	rm -f 61ccc
=======
LinkingInfo=-L/home/ff/cs61c/bin/static -l61Ccc-lexer

61Ccc : main.o parser.o parser-helpers.o parser-errors.o ast.o ast-print.o
	gcc $(Flags) -o 61Ccc main.o parser.o parser-helpers.o parser-errors.o ast.o ast-print.o $(LinkingInfo)

main.o : main.c tokens.h tokenizer.h parser.h parser-errors.h preprocessor.h ast.h ast-print.h
	gcc $(Flags) -c main.c

parser.o: parser.c parser.h ast.h tokens.h
	gcc $(Flags) -c parser.c

parser-helpers.o: parser-helpers.c parser-helpers.h ast.h tokens.h
	gcc $(Flags) -c parser-helpers.c

parser-errors.o: parser-errors.c parser-errors.h ast.h
	gcc $(Flags) -c parser-errors.c

ast.o: ast.c ast.h
	gcc $(Flags) -c ast.c

ast-print.o: ast-print.c ast-print.h ast.h
	gcc $(Flags) -c ast-print.c

clean:
	rm -f *.o
	rm -f 61Ccc
>>>>>>> d131e96a07341c217af534377ca6862ad38ce1f5

.PHONY: clean
