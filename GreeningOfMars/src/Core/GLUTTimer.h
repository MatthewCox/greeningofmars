#pragma once

class CGLUTTimer
{
public:
	CGLUTTimer(void);
	CGLUTTimer(float p_timeCount);
	~CGLUTTimer(void);

	void Update();
	bool Ready();
	float DT();

private:
	void Init(float p_timeCount);
	void CalcDT(const int& p_startTime, const int& p_endTime);

	int timeNow, timeLast, dt;
	float f_dt;
	int timeIncrement, timeNext, timeLastReady;
};
