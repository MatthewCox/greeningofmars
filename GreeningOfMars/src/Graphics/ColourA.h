#pragma once

#include "Colour.h"

/****************************************************************************
* 																			*
* ColourA																	*
* 																			*
* Holds a colour in RGBA format, and provides methods to retrieve, set, and	*
* apply each component. It is written as an extension of 'Colour'			*
* 																			*
* Written by Matthew Cox, 2010												*
* 																			*
****************************************************************************/
class ColourA : public Colour
{
public:
	// Default constructor, initializes all colour components to 1.0f
	ColourA(void);
	// Single-value constructor, initializes all colour components to the same value
	ColourA(const float& p_rgba);
	// Two-value constructor, initializes rgb components to the same value, and alpha to a different value
	ColourA(const float& p_rgb, const float& p_alpha);
	// Full constructor, initializes colour components to those specified
	ColourA(const float& p_r, const float& p_g, const float& p_b, const float& p_a);
	// Destructor
	~ColourA(void);

	// Returns the colour's alpha component
	float A() const;

	// Sets the colour's alpha component
	void A(const float& p_a);

	// Sets all of the colour's components
	void SetColour(const float& p_r, const float& p_g, const float& p_b, const float& p_a);

	// Calls glColor4f with the colour's components as parameters, thereby causing all subsequent drawing operations to use this colour
	void Apply() const;

protected:
	float a;

};
