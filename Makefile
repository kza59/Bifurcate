CXX = g++
CXXFLAGS = -Wall -std=c++11
HEADERS = config.h 
SFML_LIBS = -lsfml-graphics -lsfml-system -lsfml-window

SRC = main.cpp Game.cpp config.cpp

OUT = main

all: $(OUT)

$(OUT): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(SFML_LIBS)

clean: 
	rm -f $(OUT)


# riscv: $(SOURCES) $(HEADERS)
# 	gcc $(CFLAGS) -o $@ $(SOURCES)