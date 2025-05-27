all: example1 example2 example3 example4

.outputFolder:
	mkdir -p out
	
example1: .outputFolder
	clang -std=c++20 -lstdc++ -lm example1.cpp -Wall -Wextra -Werror -o out/example1
	./out/example1
example2: .outputFolder
	clang -std=c++20 -lstdc++ -lm example2.cpp -Wall -Wextra -Werror -o out/example2
	./out/example2
example3: .outputFolder
	clang -std=c++20 -lstdc++ -lm example3.cpp -Wall -Wextra -Werror -o out/example3
	./out/example3
example4: .outputFolder
	clang -std=c++20 -lstdc++ -lm example4.cpp -Wall -Wextra -Werror -o out/example4
	./out/example4		

