COMPILER=clang++ -std=c++11 -stdlib=libc++ -Weverything -Wno-c++98-compat
BUILD_DIRECTORY=build

build: Makefile
	mkdir -p $(BUILD_DIRECTORY)

clean:
	rm -rf "$(BUILD_DIRECTORY)"

auto: build auto/basic.cpp
	$(COMPILER) auto/basic.cpp -o $(BUILD_DIRECTORY)/auto_basic

run: auto
	./$(BUILD_DIRECTORY)/auto_basic