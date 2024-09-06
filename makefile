COMP = cc
CFLAGS = -Iinclude
LDFLAGS = -Llib -lglfw3 -lgdi32

SRC = src/*.c src/ext/*.c

default: release

init:
	mkdir lib
	echo Install GLFW from https://www.glfw.org
	echo Look for libglfw.a in the downloaded archive, and put it in the lib/ directory

dist:
	mkdir dist

release: dist
	$(COMP) $(SRC) \
	$(CFLAGS) $(LDFLAGS) \
	-O3 -s -static \
	-o dist/release