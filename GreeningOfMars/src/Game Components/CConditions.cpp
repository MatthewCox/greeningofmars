#include "CConditions.h"

CConditions::CConditions(void)
{
	waterLevel = 4.5f;
}

CConditions::~CConditions(void)
{
}

void CConditions::Update(float f_dt)
{
	
}

void CConditions::GetTemps(float &out_min,
						  float &out_avg,
						  float &out_max) const
{
	out_min = minimumTemp;
	out_avg = averageTemp;
	out_max = maximumTemp;
}

float CConditions::GetSurfacePressure() const
{
	return surfacePressure;
}

float CConditions::GetWaterLevel() const
{
	return waterLevel;
}

void CConditions::GetGases(float &out_oxygen,
						  float &out_greenhouse,
						  float &out_neutral,
						  float &out_ozone) const
{
	out_oxygen = gasOxygen;
	out_greenhouse = gasGreenhouse;
	out_neutral = gasNeutral;
	out_ozone = gasOzone;
}

void CConditions::SetWaterLevel(float p_waterLevel)
{
	waterLevel = p_waterLevel;
}

void CConditions::ChangeWaterLevel(float p_waterLevelChange)
{
	waterLevel += p_waterLevelChange;
}