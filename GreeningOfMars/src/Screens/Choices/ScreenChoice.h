#pragma once

#include "../Screen.h"

#include <vector>

#include "../../Game Components/Camera.h"
#include "../../Game Components/Mars.h"

#include "../../UI/Panel.h"
#include "../../UI/Label.h"
#include "../../UI/Button.h"

class ScreenChoice : public CScreen
{
public:
	ScreenChoice(void);
	~ScreenChoice(void) = 0;

	virtual void Update(float f_dt);
	virtual void Draw();

	virtual void Load();
	virtual void Unload();

protected:
	Camera *camera;
	Mars *mars;

	Panel *panelChoice;
	Label *labelTitle;
	Button *buttonChoice1;
	Button *buttonChoice2;
	Button *buttonChoice3;
	Button *buttonChoice4;
	Panel *panelChoiceTitle;
	Label *labelChoiceTitle;
	Panel *panelDescription;
	Panel *panelStat;
	Button *buttonGo;

	char *methodChosen;
};
