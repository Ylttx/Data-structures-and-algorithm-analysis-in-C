CFLAGS=-Wall -g -I./include # 可以自动从include中找到头文件，无需在每个.c中加入路径
OBJECTS=main.o list.o test_list.o stack.o test_stack.o

vpath %.c main:lib:test # 从lib、test中找.c文件，否则无法自动推导

out:$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(OBJECTS):./include/*.h

.PHONY:clean
clean:
	rm -f out *.o
