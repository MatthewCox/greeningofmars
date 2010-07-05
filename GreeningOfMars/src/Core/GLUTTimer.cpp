#include "GLUTTimer.h"

#include <GL/freeglut.h>

CGLUTTimer::CGLUTTimer(void)
{
	Init(60.f);
}

CGLUTTimer::CGLUTTimer(float p_timeCount)
{
	Init(p_timeCount);
}

void CGLUTTimer::Init(float p_timeCount)
{
	dt = 1;
	f_dt = 0.01f;
	timeLast = glutGet(GLUT_ELAPSED_TIME);
	timeIncrement = (int)((1.f / p_timeCount) * 1000.f);
	timeLastReady = timeLast;
	timeNext = timeLast + timeIncrement;
}

CGLUTTimer::~CGLUTTimer(void)
{
}

void CGLUTTimer::Update()
{
	timeNow = glutGet(GLUT_ELAPSED_TIME);

	CalcDT(timeLast, timeNow);

	timeLast = timeNow;
}

bool CGLUTTimer::Ready()
{
	Update();
	if (timeNow >= timeNext)
	{
		CalcDT(timeLastReady, timeNow);
		timeLastReady = timeNow;
		timeNext = timeNow + timeIncrement;
		return true;
	}
	return false;
}

float CGLUTTimer::DT()
{
	return f_dt;
}

void CGLUTTimer::CalcDT(const int& p_startTime, const int& p_endTime)
{
	dt = p_endTime - p_startTime;
	f_dt = (float)dt * 0.001f;
}
