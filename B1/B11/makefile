all: ticTacToeResult typicalTransformations

.outputFolder:
	mkdir -p out
	
ticTacToeResult: .outputFolder
	clang -std=c++17 -lstdc++ -lm ticTacToeResult.cpp -Wall -Wextra -Werror -o out/ticTacToeResult
	./out/ticTacToeResult
	
typicalTransformations: .outputFolder
	clang -std=c++17 -lstdc++ -lm typicalTransformations.cpp -o out/typicalTransformations
	./out/typicalTransformations

