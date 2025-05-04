all: loop

.outDir:
	mkdir -p cppout

loop: .outDir
	g++ -std=c++17 -lstdc++ sum_loop.cpp -o cppout/sum_loop
	./cppout/sum_loop	