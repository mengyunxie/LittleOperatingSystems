CC = g++
CFLAGS = -std=c++11

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = LittleOperatingSystems

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
