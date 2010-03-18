#pragma once

#include "Panel.h"

#include "Label.h"

class Button : public Panel
{
public:
	Button();
	Button(
		float p_x, float p_y,
		float p_width, float p_height,
		char* p_name, char* p_fontPath);
	~Button(void);

	virtual void Update(float f_dt);
	void Draw(void);
	bool CheckClicked(const int &p_x, const int &p_y) const;

protected:
	Label* label;
};
