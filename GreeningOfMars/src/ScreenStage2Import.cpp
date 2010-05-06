#include "ScreenStage2Import.h"

#include "Camera.h"
#include "Mars.h"
#include "SwishyButton.h"

#include "HUD.h"
#include "Settings.h"
#include "MouseHandler.h"
#include "Screens.h"

ScreenStage2Import::ScreenStage2Import(void)
{
}

ScreenStage2Import::~ScreenStage2Import(void)
{
}

void ScreenStage2Import::Update(float f_dt)
{
	mars->Update(f_dt);

	if (mars->Conditions()->GetWaterLevel() < 4.899f)
	{
		mars->Conditions()->ChangeWaterLevel(
			(4.9f - mars->Conditions()->GetWaterLevel()) * f_dt
			);
	}
	else
	{
		mars->Conditions()->SetWaterLevel(4.9f);

		buttonNextStage->Update(f_dt);

		int mouseX, mouseY;
		MouseHandler::GetPosition(mouseX, mouseY);
		if (MouseHandler::Pressed(0) && buttonNextStage->CheckClicked(mouseX, mouseY))
		{
			ScreenManager::GetInstance()->ChangeScreen(new ScreenMenu());
		}
	}
}

void ScreenStage2Import::Draw()
{
	camera->Display();

	mars->Draw();

	HUD::Start(Settings::View::Width, Settings::View::Height);
		buttonNextStage->Draw();
	HUD::End();
}

void ScreenStage2Import::Load()
{
	camera = new Camera(
		Vector3f(0.0f, 0.0f, 15.0f),
		0.0f, 0.0f);

	mars = new Mars();

	buttonNextStage = new SwishyButton(
		Vector2f(Settings::View::Width - 160.0f, Settings::View::Height - 40.0f),
		Vector2f(180.0f, 40.0f),
		"Next Stage",
		Settings::UI::FontPath,
		Settings::UI::ButtonColour,
		1);
	buttonNextStage->SwishOn();
}

void ScreenStage2Import::Unload()
{
	delete mars;
	delete camera;
	delete buttonNextStage;
}