exec = start.exe
sources = $(wildcard C_algorithm/*.c)
objects = $(sources:.c=.o)
flags = -g


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

clean:
	del /Q /F start.exe
	del /Q /F C_algorithm\lexer.o C_algorithm\main.o C_algorithm\read.o C_algorithm\parser.o