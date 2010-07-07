#include "ColourA.h"

#include <GL/freeglut.h>

ColourA::ColourA(void)
{
	A(1.0f);
}

ColourA::ColourA(const float& p_rgba) : Colour(p_rgba)
{
	A(p_rgba);
}

ColourA::ColourA(const float& p_rgb, const float& p_alpha) : Colour(p_rgb)
{
	A(p_alpha);
}

ColourA::ColourA(const float& p_r, const float& p_g, const float& p_b, const float& p_a) : Colour(p_r, p_g, p_b)
{
	A(p_a);
}

ColourA::~ColourA(void)
{
}

float ColourA::A() const {return a;}

void ColourA::A(const float& p_a) {a = p_a;}

void ColourA::SetColour(const float& p_r, const float& p_g, const float& p_b, const float& p_a)
{
	Colour::SetColour(p_r, p_g, p_b);
	A(p_a);
}

void ColourA::Apply() const
{
	glColor4f(r, g, b, a);
}