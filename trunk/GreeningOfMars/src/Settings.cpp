#include "Settings.h"

int Settings::View::Width = 1024;
int Settings::View::Height = 768;
double Settings::View::FOV = 75.0;
bool Settings::View::Fullscreen = false;

float Settings::Mouse::MovementRatio = 0.3f;

Settings::Settings(void)
{
}

Settings::~Settings(void)
{
}
