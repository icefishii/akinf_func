all: add immutabilityPassByValue immutabilityPassByReference immutabilityPointers lambdaIO immutableCapture lambdasAndClasses

.outputFolder:
	mkdir -p out

add: .outputFolder
	clang -std=c++17 -lstdc++ add.cpp -o out/add
	./out/add

immutabilityPassByValue: .outputFolder
	clang -std=c++17 -lstdc++ immutabilityPassByValue.cpp -o out/immutabilityPassByValue
	./out/immutabilityPassByValue

immutabilityPassByReference: .outputFolder
	clang -std=c++17 -lstdc++ immutabilityPassByReference.cpp -o out/immutabilityPassByReference
	./out/immutabilityPassByReference

immutabilityPointers: .outputFolder
	clang -std=c++17 -lstdc++ immutabilityPointers.cpp -o out/immutabilityPointers
	./out/immutabilityPointers

lambdaIO: .outputFolder
	clang -std=c++17 -lstdc++ lambdaIO.cpp -o out/lambdaIO
	./out/lambdaIO

immutableCapture: .outputFolder
	clang -std=c++17 -lstdc++ immutableCapture.cpp -o out/immutableCapture
	./out/immutableCapture

lambdasAndClasses: .outputFolder
	clang -std=c++17 -lstdc++ lambdasAndClasses.cpp -o out/lambdasAndClasses
	./out/lambdasAndClasses
