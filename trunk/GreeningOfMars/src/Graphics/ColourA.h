#pragma once

#include "Colour.h"

class ColourA : public Colour
{
public:
	ColourA(void);
	ColourA(float p_r, float p_g, float p_b, float p_a);
	ColourA(float p_colour);
	~ColourA(void);

	float A() const;

	void SetA(float p_a);

	void SetColour(float p_r, float p_g, float p_b, float p_a);

	void Apply() const;

protected:
	float a;
};
