all: compile_and_start

compile:
	g++ -o main ./src/*.cpp -Lsrc/lib -Isrc/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

compile_and_start:
	g++ -o main ./src/*.cpp -Lsrc/lib -Isrc/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./main.exe