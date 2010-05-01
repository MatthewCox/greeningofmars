#pragma once

#include "Button.h"

#include "Vector2f.h"

class SwishyButton : public Button
{
public:
	SwishyButton(void);
	SwishyButton(
		Vector2f p_position,
		Vector2f p_size,
		char* p_name, char* p_fontPath,
		ColourA p_colour,
		int p_swishDir);
	~SwishyButton(void);

	void Update(float f_dt);

	void SwishOn();
	void SwishOff();
private:
	Vector2f origin;
	Vector2f target;
	int swishDir;
	int originSwishDir;
	bool swishing;
};
