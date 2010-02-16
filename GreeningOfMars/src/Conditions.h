#pragma once

class Conditions
{
private:
	float minimumTemp, averageTemp, maximumTemp;
	float surfacePressure;
	float waterLevel;
	float gasOxygen, gasGreenhouse, gasNeutral, gasOzone;

public:
	Conditions(void);
	~Conditions(void);

	void Update(float f_dt);
};
