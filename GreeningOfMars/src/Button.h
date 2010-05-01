#pragma once

#include "Panel.h"

#include "Label.h"

class Button : public Panel
{
public:
	Button();
	Button(
		Vector2f p_position,
		Vector2f p_size,
		char* p_name, char* p_fontPath,
		ColourA p_colour);
	~Button(void);

	virtual void Update(float f_dt);
	void Draw(void);
	bool CheckClicked(const int &p_x, const int &p_y) const;

protected:
	Label* label;
};
