#pragma once

#include "Screen.h"

#include "Camera.h"
#include "Mars.h"

#include "Panel.h"
#include "Label.h"
#include "Button.h"

class ScreenChoiceStage1 : public Screen
{
public:
	ScreenChoiceStage1(void);
	~ScreenChoiceStage1(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();

private:
	Camera *camera;
	Mars *mars;

	Panel *panelChoice;
	Label *labelChoiceTitle;
	Button *buttonChoice1;
	Button *buttonChoice2;
	Button *buttonChoice3;
	Button *buttonChoice4;
	Panel *panelTitle;
	Label *labelTitle;
	Panel *panelDescription;
	Panel *panelStat;
	Button *buttonGo;

	char *methodChosen;
};
