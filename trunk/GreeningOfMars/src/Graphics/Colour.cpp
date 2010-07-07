#include "Colour.h"

#include <GL/freeglut.h>

Colour::Colour(void)
{
	SetColour(1.0f, 1.0f, 1.0f);
}

Colour::Colour(const float& p_r, const float& p_g, const float& p_b)
{
	SetColour(p_r, p_g, p_b);
}

Colour::Colour(const float& p_colour)
{
	SetColour(p_colour, p_colour, p_colour);
}

Colour::~Colour(void)
{
}

float Colour::R() const {return r;}
float Colour::G() const {return g;}
float Colour::B() const {return b;}

void Colour::R(const float& p_r) {r = p_r;}
void Colour::G(const float& p_g) {g = p_g;}
void Colour::B(const float& p_b) {b = p_b;}

void Colour::SetColour(const float& p_r, const float& p_g, const float& p_b)
{
	R(p_r);
	G(p_g);
	B(p_b);
}

void Colour::Apply() const
{
	glColor3f(r, g, b);
}