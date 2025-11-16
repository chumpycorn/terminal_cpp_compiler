CXX = g++
CXXFLAGS = -std=c++17 -O2

SOURCES = main.cpp Editor.cpp FileIO.cpp Runner.cpp
HEADERS = Editor.h FileIO.h Runner.h

OBJS = $(SOURCES:.cpp=.o)
TARGET = tinyeditor

all: $(TARGET)

$(TARGET): $(OBJS)
$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
$(CXX) $(CXXFLAGS) -c $<

clean:
rm -f $(OBJS) $(TARGET) tmp_exec tmp_compile_errors.txt

.PHONY: all clean
