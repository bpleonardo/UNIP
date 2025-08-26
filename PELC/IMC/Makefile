main: main.c
	mkdir -p build
	gcc -o build/main main.c

run: main
	echo
	./build/main

.PHONY: clean
clean:
	rm -r ./build