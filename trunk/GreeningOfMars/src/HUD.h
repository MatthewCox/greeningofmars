#pragma once

#include <windows.h>

#include "GL/gl.h"
#include "GL/freeglut.h"

class HUD
{
public:
    HUD(void);
    ~HUD(void);

    static void Start(int p_width, int p_height);
    static void End(void);
};