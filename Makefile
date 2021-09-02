build:

	gcc main.c calc.c -ansi --pedantic-errors -Wall -o ..\build\main.exe

run:

	start main.exe

speak:

	echo "This is a test echo"