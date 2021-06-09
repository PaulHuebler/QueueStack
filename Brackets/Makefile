CC = gcc
CFLAGS = -c -Wextra -O3
LD = $(CC)
LDFLAGS =

TARGET = test
OBJECTS = test.o stack.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)