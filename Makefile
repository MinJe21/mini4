CC = gcc
TARGET = manager
DTARGET = manager_debug
OBJECTS = main.c manager.o
all:$(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(DTARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -DDEBUG -o $(DTARGET)

clean:
	rm *.o manager
	
	
	


