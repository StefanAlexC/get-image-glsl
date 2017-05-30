#ifndef __GETIMAGE_COMMON__
#define __GETIMAGE_COMMON__

#include <stdlib.h> // exit()
#include <stdio.h>  // printf()

#include <string>

/*---------------------------------------------------------------------------*/
// Parameters

typedef enum {
    Ctx_EGL,
    Ctx_GLFW,
} ContextProvider;

/*---------------------------------------------------------------------------*/
/*
typedef enum {
    // GLSL (regular)
    GLSLv110,
    GLSLv440,
    // GLSL ES
    GLSLv100,
    GLSLv300es,
} GLSLVersion;
*/
/*---------------------------------------------------------------------------*/

typedef struct {
    int width;
    int height;
    ContextProvider contextProvider;
    int version;
    std::string output;
} Params;

/*---------------------------------------------------------------------------*/

#define crash(fmt, ...) do {                                            \
        printf("%s:%d (%s) ERROR: ", __FILE__, __LINE__, __func__);     \
        printf(fmt, ##__VA_ARGS__);                                     \
        printf("\n");                                                   \
        exit (EXIT_FAILURE);                                            \
    } while (0)

/*---------------------------------------------------------------------------*/

#endif
