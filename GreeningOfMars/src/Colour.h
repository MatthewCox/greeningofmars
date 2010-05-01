#pragma once

class Colour
{
public:
	Colour(void);
	Colour(float p_r, float p_g, float p_b);
	Colour(float p_colour);
	~Colour(void);

	float R() const;
	float G() const;
	float B() const;

	void SetR(float p_r);
	void SetG(float p_g);
	void SetB(float p_b);

	void SetColour(float p_r, float p_g, float p_b);

	void Apply() const;

protected:
	float r, g, b;
};
