#ifndef __GETIMAGE_OPENGLCONTEXT__
#define __GETIMAGE_OPENGLCONTEXT__

#define CONTEXT_EGL  1
#define CONTEXT_GLFW 2

#if   (GETIMAGE_CONTEXT == CONTEXT_EGL)
#include "context_egl.h"
#elif (GETIMAGE_CONTEXT == CONTEXT_GLFW)
#include "context_glfw.h"
#else
#error Must define an OpenGL context preprocessor macro!
#endif

/*---------------------------------------------------------------------------*/
// Primitives all context should define

void contextInitAndGetAPI(Params& params, Context& ctx);
bool contextKeepLooping(Context &ctx);
void contextSwap(Context& ctx);
void contextSetKeyCallback(Context& ctx);
void contextTerminate(Context& ctx);

/*---------------------------------------------------------------------------*/
// This one is defined is main.cpp, but used in the macro belows

const char *openglErrorString(GLenum err);

/*---------------------------------------------------------------------------*/

#define GL_CHECKERR(strfunc) do {                                       \
        GLenum __err = glGetError();                                    \
        if (__err != GL_NO_ERROR) {                                     \
            crash("OpenGL error: %s(): %s" , strfunc, openglErrorString(__err)); \
        }                                                               \
    } while (0)

/*---------------------------------------------------------------------------*/

#define GL_SAFECALL(func, ...) do  {                    \
        func(__VA_ARGS__);                              \
        GL_CHECKERR(#func);                             \
    } while (0)

/*---------------------------------------------------------------------------*/

#endif
