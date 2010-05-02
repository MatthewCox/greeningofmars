#pragma once

class CConditions
{
private:
	float minimumTemp, averageTemp, maximumTemp;
	float surfacePressure;
	float waterLevel;
	float gasOxygen, gasGreenhouse, gasNeutral, gasOzone;

public:
	CConditions(void);
	~CConditions(void);

	void Update(float f_dt);

	void GetTemps(
		float &out_min,
		float &out_avg,
		float &out_max) const;
	float GetSurfacePressure() const;
	float GetWaterLevel() const;
	void GetGases(
		float &out_oxygen,
		float &out_greenhouse,
		float &out_neutral,
		float &out_ozone) const;
	float GetOxygen() const;
	float GetGreenhouse() const;
	float GetNeutral() const;
	float GetOzone() const;

	void SetMinTemp(float );
	void SetAvgTemp(float );
	void SetMaxTemp(float );
	void SetSurfacePressure(float );
	void SetWaterLevel(float );
	void SetOxygen(float );
	void SetGreenhouse(float );
	void SetNeutral(float );
	void SetOzone(float );

	void ChangeTemps(
		float p_minChange,
		float p_avgChange,
		float p_maxChange);
	void ChangeSurfacePressure(float p_pressureChange);
	void ChangeWaterLevel(float p_waterLevelChange);
	void ChangeGases(
		float p_oxygenChange,
		float p_greenhouseChange,
		float p_neutralChange,
		float p_ozoneChange);
};
