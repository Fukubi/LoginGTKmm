CC = g++
CXX_FLAGS = -I./includes/ -Wall `pkg-config --cflags --libs gtkmm-3.0`
LD_FLAGS = -o testing
SOURCES = *.cpp

all: $(SOURCES)
	$(CC) $(LD_FLAGS) $^ $(CXX_FLAGS)
