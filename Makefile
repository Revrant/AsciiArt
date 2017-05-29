AsciiArt: main.o
	g++ main.o -o AsciiArt
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm main.o AsciiArt
