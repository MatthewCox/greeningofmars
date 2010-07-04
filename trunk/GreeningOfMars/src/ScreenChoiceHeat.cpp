#include "ScreenChoiceHeat.h"

#include "Screens.h"
#include "MouseHandler.h"

ScreenChoiceHeat::ScreenChoiceHeat(void)
{
}

ScreenChoiceHeat::~ScreenChoiceHeat(void)
{
}

void ScreenChoiceHeat::Update(float f_dt)
{
	ScreenChoice::Update(f_dt);

	if (MouseHandler::Released(0))
	{
		int mouseX = 0;
		int mouseY = 0;
		MouseHandler::GetPosition(mouseX, mouseY);

		if (buttonGo->CheckClicked(mouseX, mouseY))
		{
			if (labelChoiceTitle->Name() == buttonChoice2->Name())
			{
				CScreenManager::GetInstance()->ChangeScreen(new ScreenStage1Asteroid());
			}
			else
			{
				labelChoiceTitle->Name("Please choose a method.");
			}
		}
	}
}

void ScreenChoiceHeat::Draw()
{
	ScreenChoice::Draw();
}

void ScreenChoiceHeat::Load()
{
	ScreenChoice::Load();

	labelTitle->Name("Heat and Atmosphere");
	buttonChoice1->Name("Greenhouse");
	buttonChoice2->Name("Asteroid");
	buttonChoice3->Name("Surface");
	buttonChoice4->Name("Machines");
}

void ScreenChoiceHeat::Unload()
{
	ScreenChoice::Unload();
}