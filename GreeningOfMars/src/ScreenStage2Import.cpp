#include "ScreenStage2Import.h"

#include "Camera.h"
#include "Mars.h"

ScreenStage2Import::ScreenStage2Import(void)
{
}

ScreenStage2Import::~ScreenStage2Import(void)
{
}

void ScreenStage2Import::Update(float f_dt)
{
	if (mars->Conditions()->GetWaterLevel() < 4.8999f)
	{
		mars->Conditions()->ChangeWaterLevel(
			(4.9f - mars->Conditions()->GetWaterLevel()) * f_dt
			);
	}
	else
	{
		mars->Conditions()->SetWaterLevel(4.9f);
	}

	mars->Update(f_dt);
}

void ScreenStage2Import::Draw()
{
	camera->Display();

	mars->Draw();
}

void ScreenStage2Import::Load()
{
	camera = new Camera(
		Vector3f(0.0f, 0.0f, 15.0f),
		0.0f, 0.0f);

	mars = new Mars();
}

void ScreenStage2Import::Unload()
{
	delete mars;
	delete camera;
}