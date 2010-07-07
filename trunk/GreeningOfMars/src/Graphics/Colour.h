#pragma once

/****************************************************************************
* 																			*
* Colour																	*
* 																			*
* Holds a colour in RGB format, and provides methods to retrieve, set and	*
* apply each component.														*
* 																			*
* Written by Matthew Cox, 2010												*
* 																			*
****************************************************************************/
class Colour
{
public:
	// Default constructor, initializes all colour components to 1.0f
	Colour(void);
	// Single-value constructor, initializes all colour components to the same value
	Colour(const float& p_rgb);
	// Full constructor, initializes colour components to those specified
	Colour(const float& p_r, const float& p_g, const float& p_b);
	// Destructor
	~Colour(void);

	// Returns the colour's red component
	float R() const;
	// Returns the colour's green component
	float G() const;
	// Returns the colour's blue component
	float B() const;

	// Sets the colour's red component
	void R(const float& p_r);
	// Sets the colour's green component
	void G(const float& p_g);
	// Sets the colour's blue component
	void B(const float& p_b);

	// Sets all of the colour's components
	void SetColour(const float& p_r, const float& p_g, const float& p_b);

	// Calls glColor3f with the colour's components as parameters, thereby causing all subsequent drawing operations to use this colour
	void Apply() const;

protected:
	float r, g, b;

};
