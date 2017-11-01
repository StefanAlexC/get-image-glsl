CXX=g++-7
CFLAGS=-std=c++11 -g -Wall

EGL_INCLUDE=-I.
EGL_LDFLAGS=-lEGL -lGLESv2

GLFW_INCLUDE=-I. -I include -I $(HOME)/work/glfw-3.2.1/include -I /usr/local/include
GLFW_LDFLAGS=-L $(HOME)/work/glfw-3.2.1/build/src -L /usr/local/lib -lglfw -ldl

all: get_image_glfw

# EGL
#get_image_egl: main.cpp lodepng.o context_egl.o json.hpp
#	$(CXX) $(CFLAGS) -DGETIMAGE_CONTEXT=CONTEXT_EGL -o $@ $(EGL_INCLUDE) $+ $(EGL_LDFLAGS)

#context_egl.o: context_egl.cpp
#	$(CXX) $(CFLAGS) -c $(EGL_INCLUDE) $?

# GLFW
get_image_glfw: main.cpp lodepng.o context_glfw.o glad.o json.hpp
	$(CXX) $(CFLAGS) -DGETIMAGE_CONTEXT=CONTEXT_GLFW -o $@ $(GLFW_INCLUDE) $+ $(GLFW_LDFLAGS)

context_glfw.o: context_glfw.cpp
	$(CXX) $(CFLAGS) -c $(GLFW_INCLUDE) $?

glad.o: glad.c
	$(CXX) $(CFLAGS) -c $(GLFW_INCLUDE) $?

# PNG library
lodepng.o: lodepng.cpp
	$(CXX) $(CFLAGS) -c $(INCLUDE) $?

PHONY: clean

clean:
	rm -f get_image *.o *.h.gch
