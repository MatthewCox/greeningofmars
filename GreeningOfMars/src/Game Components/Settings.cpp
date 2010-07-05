#include "Settings.h"

#include "../Core/IniHandler.h"

int Settings::View::Width = 1024;
int Settings::View::Height = 768;
double Settings::View::FOV = 75.0;
bool Settings::View::Fullscreen = false;

float Settings::Mouse::MovementRatio = 10.0f;

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

	float r, g, b, a;
	r = IniHandler::ReadFloat("UI", "LabelColourR", 1.0f);
	g = IniHandler::ReadFloat("UI", "LabelColourG", 1.0f);
	b = IniHandler::ReadFloat("UI", "LabelColourB", 1.0f);
	a = IniHandler::ReadFloat("UI", "LabelColourA", 1.0f);
	UI::LabelColour = ColourA(r, g, b, a);
	r = IniHandler::ReadFloat("UI", "PanelColourR", 0.0f);
	g = IniHandler::ReadFloat("UI", "PanelColourG", 0.2f);
	b = IniHandler::ReadFloat("UI", "PanelColourB", 0.4f);
	a = IniHandler::ReadFloat("UI", "PanelColourA", 0.8f);
	UI::PanelColour = ColourA(r, g, b, a);
	r = IniHandler::ReadFloat("UI", "ButtonColourR", 0.2f);
	g = IniHandler::ReadFloat("UI", "ButtonColourG", 0.4f);
	b = IniHandler::ReadFloat("UI", "ButtonColourB", 0.6f);
	a = IniHandler::ReadFloat("UI", "ButtonColourA", 1.0f);
	UI::ButtonColour = ColourA(r, g, b, a);
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

	IniHandler::WriteFloat("UI", "LabelColourR", UI::LabelColour.R());
	IniHandler::WriteFloat("UI", "LabelColourG", UI::LabelColour.G());
	IniHandler::WriteFloat("UI", "LabelColourB", UI::LabelColour.B());
	IniHandler::WriteFloat("UI", "LabelColourA", UI::LabelColour.A());

	IniHandler::WriteFloat("UI", "PanelColourR", UI::PanelColour.R());
	IniHandler::WriteFloat("UI", "PanelColourG", UI::PanelColour.G());
	IniHandler::WriteFloat("UI", "PanelColourB", UI::PanelColour.B());
	IniHandler::WriteFloat("UI", "PanelColourA", UI::PanelColour.A());

	IniHandler::WriteFloat("UI", "ButtonColourR", UI::ButtonColour.R());
	IniHandler::WriteFloat("UI", "ButtonColourG", UI::ButtonColour.G());
	IniHandler::WriteFloat("UI", "ButtonColourB", UI::ButtonColour.B());
	IniHandler::WriteFloat("UI", "ButtonColourA", UI::ButtonColour.A());
}