run: play_game.o start.o menu.o
	g++ play_game.o start.o menu.o -o run

play_game.o: play_game.cpp
	g++ -c play_game.cpp 

start.o: start.cpp
	g++ -c start.cpp 

menu.o: menu.cpp
	g++ -c menu.cpp

clean:
	rm *.o
