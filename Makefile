BUILD_DIR = build
BUILD_TYPE ?= Debug
CMAKE_DIR = $(CURDIR)


all: cmake
.PHONY: all


cmake:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR); cmake \
		-D CMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		$(CMAKE_DIR) ; \
		make
.PHONY: cmake


test: cmake
	cd $(BUILD_DIR); cmake \
		-D CMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		$(CMAKE_DIR) ; \
		make build_test; \
		make test
.PHONY: test


run:
	time ./build/main res/integer_array.txt
.PHONY: run


clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean
