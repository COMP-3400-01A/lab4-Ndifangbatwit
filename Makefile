CFLAGS += -Wall -Wextra -Wfatal-errors -g3
CFLAGS += -Werror=vla -Werror=shadow -Wno-unused -Wno-unused-parameter
CFLAGS += -fsanitize=address -fsanitize=undefined

aall: build/parta build/partb build/partc

build:
	mkdir -p build

build/parta: parta.c | build
	$(CC) $(CFLAGS) -o build/parta parta.c

build/partb: partb.c | build
	$(CC) $(CFLAGS) -o build/partb partb.c

build/partc: partc.c | build
	$(CC) $(CFLAGS) -o build/partc partc.c

.PHONY: clean
clean:
	rm -rf build
