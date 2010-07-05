#include "ColourA.h"

#include <GL/freeglut.h>

ColourA::ColourA(void)
{
	SetA(1.0f);
}

ColourA::ColourA(float p_r, float p_g, float p_b, float p_a) : Colour(p_r, p_g, p_b)
{
	SetA(p_a);
}

ColourA::ColourA(float p_colour) : Colour(p_colour)
{
	SetA(p_colour);
}

ColourA::~ColourA(void)
{
}

float ColourA::A() const {return a;}

void ColourA::SetA(float p_a) {a = p_a;}

void ColourA::SetColour(float p_r, float p_g, float p_b, float p_a)
{
	Colour::SetColour(p_r, p_g, p_b);
	SetA(p_a);
}

void ColourA::Apply() const
{
	glColor4f(r, g, b, a);
}