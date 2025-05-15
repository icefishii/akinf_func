all: basicFunctionalComposition composeFunctions decomposeMultipleArguments

.outputFolder:
	mkdir -p out

basicFunctionalComposition: .outputFolder
	clang -std=c++17 -lstdc++ -lm basicFunctionalComposition.cpp -o out/basicFunctionalComposition
	./out/basicFunctionalComposition

composeFunctions: .outputFolder
	clang -std=c++17 -lstdc++ -lm composeFunctions.cpp -o out/composeFunctions
	./out/composeFunctions

decomposeMultipleArguments: .outputFolder
	clang -std=c++17 -lstdc++ -lm decomposeMultipleArguments.cpp -o out/decomposeMultipleArguments
	./out/decomposeMultipleArguments
