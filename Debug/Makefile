CXX=g++
CXXFLAGS=-std=c++11
SRCS=
OBJS=$(SRCS:.cpp=.o)
TARGET=Debug

all: $(TARGET)

$(OBJS): %.o : %.h

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ main.cpp -o $@

.PHONY: clean

clean:
	rm -f $(TARGET) *.o
