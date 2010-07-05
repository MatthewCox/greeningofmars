#include "Colour.h"

#include <GL/freeglut.h>

Colour::Colour(void)
{
	SetColour(1.0f, 1.0f, 1.0f);
}

Colour::Colour(float p_r, float p_g, float p_b)
{
	SetColour(p_r, p_g, p_b);
}

Colour::Colour(float p_colour)
{
	SetColour(p_colour, p_colour, p_colour);
}

Colour::~Colour(void)
{
}

float Colour::R() const {return r;}
float Colour::G() const {return g;}
float Colour::B() const {return b;}

void Colour::SetR(float p_r) {r = p_r;}
void Colour::SetG(float p_g) {g = p_g;}
void Colour::SetB(float p_b) {b = p_b;}

void Colour::SetColour(float p_r, float p_g, float p_b)
{
	SetR(p_r);
	SetG(p_g);
	SetB(p_b);
}

void Colour::Apply() const
{
	glColor4f(r, g, b, 1.0f);
}