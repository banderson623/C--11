COMPILER=clang++ -std=c++11 -stdlib=libc++ -Weverything -Wno-c++98-compat
BUILD_DIRECTORY=build

all: auto decltype nullptr foreach override

build: Makefile
	mkdir -p $(BUILD_DIRECTORY)

clean:
	rm -rf "$(BUILD_DIRECTORY)"

auto: build auto.cpp
	$(COMPILER) auto.cpp -o $(BUILD_DIRECTORY)/auto

decltype: build decltype.cpp
	$(COMPILER) decltype.cpp -o $(BUILD_DIRECTORY)/decltype

nullptr: build nullptr.cpp
	$(COMPILER) nullptr.cpp -o $(BUILD_DIRECTORY)/nullptr

foreach: build foreach.cpp
	$(COMPILER) foreach.cpp -o $(BUILD_DIRECTORY)/foreach

override: build override.cpp
	$(COMPILER) override.cpp -o $(BUILD_DIRECTORY)/override


run: auto decltype nullptr foreach override
	./$(BUILD_DIRECTORY)/auto
	./$(BUILD_DIRECTORY)/decltype
	./$(BUILD_DIRECTORY)/nullptr
	./$(BUILD_DIRECTORY)/foreach
	./$(BUILD_DIRECTORY)/override	