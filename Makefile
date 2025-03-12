CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/jrpg_game

SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/Character/Character.cpp \
       $(SRC_DIR)/Character/Archer.cpp \
       $(SRC_DIR)/Character/Assassin.cpp \
       $(SRC_DIR)/Character/Bard.cpp \
       $(SRC_DIR)/Character/Berserker.cpp \
       $(SRC_DIR)/Character/Healer.cpp \
       $(SRC_DIR)/Character/Mage.cpp \
       $(SRC_DIR)/Character/Tank.cpp \
       $(SRC_DIR)/Combat/CombatSystem.cpp \
       $(SRC_DIR)/Utils/Random.cpp \
       $(SRC_DIR)/Game/Game.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)

.PHONY: all clean