#include "ScreenMenu.h"

#include "Settings.h"
#include "HUD.h"

ScreenMenu::ScreenMenu(void)
{
}

ScreenMenu::~ScreenMenu(void)
{
}

void ScreenMenu::Update(float f_dt)
{
	buttonTest->Update(f_dt);
}

void ScreenMenu::Draw()
{
	HUD::Start(Settings::View::Width, Settings::View::Height);

	buttonTest->Draw();

	HUD::End();
}

void ScreenMenu::Load()
{
	buttonTest = new SwishyButton(0.0f, (float)(Settings::View::Height / 2) - 25.0f, 200.0f, 50.0f, "Test", "C:\\Windows\\Fonts\\tahoma.ttf", 1);
}

void ScreenMenu::Unload()
{
	
}