#include "Settings.h"

#include "IniHandler.h"

int Settings::View::Width = 1024;
int Settings::View::Height = 768;
double Settings::View::FOV = 75.0;
bool Settings::View::Fullscreen = false;

float Settings::Mouse::MovementRatio = 0.3f;

float Settings::Movement::Speed = 10.0f;

char* Settings::UI::FontPath = "C:\\Windows\\Fonts\\tahoma.ttf";
ColourA Settings::UI::LabelColour = ColourA(1.0f);
ColourA Settings::UI::PanelColour = ColourA(0.0f, 0.2f, 0.4f, 0.8f);
ColourA Settings::UI::ButtonColour = ColourA(0.2f, 0.4f, 0.6f, 1.0f);

void Settings::Load(char* filepath)
{
	IniHandler::SetFileName(".\\settings.ini");
	View::Width = IniHandler::ReadInt("View", "Width", 1024);
	View::Height = IniHandler::ReadInt("View", "Height", 768);
	View::FOV = IniHandler::ReadFloat("View", "FOV", 75.0f);
	View::Fullscreen = (IniHandler::ReadInt("View", "Fullscreen", 0) == 1);

	Mouse::MovementRatio = IniHandler::ReadFloat("Mouse", "MovementRatio", 0.3f);

	Movement::Speed = IniHandler::ReadFloat("Movement", "Speed", 10.0f);

	UI::FontPath = IniHandler::ReadString("UI", "FontPath", "C:\\Windows\\Fonts\\tahoma.ttf");
}

void Settings::Save(char* filepath)
{
	IniHandler::SetFileName(".\\settings.ini");
	IniHandler::WriteInt("View", "Width", View::Width);
	IniHandler::WriteInt("View", "Height", View::Height);
	IniHandler::WriteFloat("View", "FOV", (float)View::FOV);
	IniHandler::WriteInt("View", "Fullscreen", View::Fullscreen);

	IniHandler::WriteFloat("Mouse", "MovementRatio", Mouse::MovementRatio);

	IniHandler::WriteFloat("Movement", "Speed", Movement::Speed);

	IniHandler::WriteString("UI", "FontPath", UI::FontPath);

}