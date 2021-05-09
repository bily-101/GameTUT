all:
	g++ -Wall -std=c99 ./src/*.cpp -lSDL2 -o game
	./game
	rm game

build:
	g++ -Wall -std=c99 ./src/*.cpp -lSDL2 -o game

run:
	./game
clean:
	rm game
