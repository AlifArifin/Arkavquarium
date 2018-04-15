# Masukkan semua file cpp Anda
SRCDIR = ../src

OBJS = $(addprefix $(SRCDIR)/, Account.cpp Coin.cpp Fish.cpp Food.cpp Guppy.cpp ListObj.hpp Matrix.cpp Piranha.cpp Point.cpp Snail.cpp Summonable.cpp)

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

Account : driverAccount.cpp $(OBJS)
	$(CC) driverAccount.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o account

Coin : driverCoin.cpp $(OBJS)
	$(CC) driverCoin.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o coin

Food : driverFood.cpp $(OBJS)
	$(CC) driverFood.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o food

Guppy : driverGuppy.cpp $(OBJS)
	$(CC) driverGuppy.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o guppy

Listobj : driverListObj.cpp $(OBJS)
	$(CC) driverListObj.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o listobj

Matrix : driverMatrix.cpp $(OBJS)
	$(CC) driverMatrix.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o matrix

Piranha : driverPiranha.cpp $(OBJS)
	$(CC) driverPiranha.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o piranha

Point : driverPoint.cpp $(OBJS)
	$(CC) driverPoint.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o point

Snail : driverSnail.cpp $(OBJS)
	$(CC) driverSnail.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o snail
