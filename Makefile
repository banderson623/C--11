COMPILER=clang++ -std=c++11 -stdlib=libc++ -Weverything -Wno-c++98-compat
BUILD_DIRECTORY=build

build: Makefile
	mkdir -p $(BUILD_DIRECTORY)

clean:
	rm -rf "$(BUILD_DIRECTORY)"

auto: build basic.cpp
	$(COMPILER) basic.cpp -o $(BUILD_DIRECTORY)/auto

decltype: build decltype.cpp
	$(COMPILER) decltype.cpp -o $(BUILD_DIRECTORY)/decltype


run: auto decltype
	./$(BUILD_DIRECTORY)/auto
	./$(BUILD_DIRECTORY)/decltype