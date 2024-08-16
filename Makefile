all: build

build:
	@echo "building..."
	g++ ./src/main.cc -o main

run: build
	@echo "running..."
	@./main > img

save-img: run
	@echo "saving image..."
	@./save-img.sh

.PHONY: all build run save-img
