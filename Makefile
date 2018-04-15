# Masukkan semua file cpp Anda
SRCDIR = src

OBJS = main.cpp $(addprefix $(SRCDIR)/,oop.cpp Account.cpp Aquarium.cpp Coin.cpp Fish.cpp Food.cpp Guppy.cpp ListObj.hpp Matrix.cpp Piranha.cpp Point.cpp Snail.cpp Summonable.cpp)

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = arkav
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
