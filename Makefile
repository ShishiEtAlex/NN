CC = g++
EXEC = RPG
FLAGS = -std=c++17 -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
S = src
O = obj
B = bin

all: $(O) $(B) $(O)/Main.o
	$(CC) $(O)/*.o -o $(B)/$(EXEC) $(LIBS)

$(O)/Main.o: $(O)/Engine.o 
	$(CC) $(S)/Main.cpp -c -o $(O)/Main.o $(FLAGS)

$(O)/Engine.o: $(O)/Window.o $(O)/StateManager.o
	$(CC) $(S)/engine/Engine.cpp -c -o $(O)/Engine.o $(FLAGS)

$(O)/StateManager.o: $(O)/StateWorld.o
	$(CC) $(S)/engine/StateManager.cpp -c -o $(O)/StateManager.o $(FLAGS)

$(O)/StateWorld.o: $(O)/EventManager.o
	$(CC) $(S)/engine/StateWorld.cpp -c -o $(O)/StateWorld.o $(FLAGS)

$(O)/Window.o: $(O)/EventManager.o
	$(CC) $(S)/engine/Window.cpp -c -o $(O)/Window.o $(FLAGS)

$(O)/EventManager.o:
	$(CC) $(S)/engine/EventManager.cpp -c -o $(O)/EventManager.o $(FLAGS)

clean: $(O) $(B)
	rm -r $(O)
	rm -r $(B)

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)
