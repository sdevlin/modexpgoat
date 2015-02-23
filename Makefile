CFLAGS = -O2
CPPFLAGS = -I/usr/local/include
LDFLAGS = -L/usr/local/lib
LDLIBS = -lgmp

modexpgoat : main.o
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^
