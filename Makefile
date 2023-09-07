
CC ?= gcc

APP_NAME   = server
OBJ_FILES  = server.o

APP_NAME_CLIENT   = server_client
OBJ_FILES_CLIENT  = server_client.o

LIBS = .


all: $(APP_NAME) $(APP_NAME_CLIENT)

$(APP_NAME): $(OBJ_FILES)
	$(CC) -o $@ $^

$(APP_NAME_CLIENT): $(OBJ_FILES_CLIENT)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $^ -g


clean:
	rm *.o $(APP_NAME_PIPE_SND) $(APP_NAME_CLIENT)

fresh:
	make clean
	make all
