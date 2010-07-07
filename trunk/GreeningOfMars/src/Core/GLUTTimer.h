#pragma once

/****************************************************************************
* 																			*
* GLUTTimer																	*
* 																			*
* Implements a timer using glutGet(GLUT_ELAPSED_TIME), and provides methods	*
* to update it and retrieve the amount of time since it was last updated.	*
* Two ways of using it are implemented, using either Update or Ready		*
* 																			*
* Written by Matthew Cox, 2010												*
* 																			*
****************************************************************************/
class CGLUTTimer
{
public:
	// Default constructor, if you use this one you'll have to call Init later
	CGLUTTimer(void);
	/*
	 * Full constructor
	 * Initializes the timer and sets the Ready method to return true p_timeCount times per second
	 */
	CGLUTTimer(const float& p_timeCount);
	// Destructor
	~CGLUTTimer(void);

	// Initializes the timer and sets the Ready method to return true p_timeCount times per second
	void Init(const float& p_timeCount);

	/*
	 * Updates the timer, setting a new DT value
	 * Should be called every program 'cycle' if used
	 */
	void Update();
	/*
	 * Updates the timer, setting a new DT value
	 * Should be placed as an if(timer.Ready()) around any operations
	 * you want to occur a certain number of times per second
	 */
	bool Ready();
	// Returns the amount of time that elapsed between the last calls to Update or Ready
	float DT() const;

private:
	/*
	 * Calculates the amount of time that passed between the two specified times,
	 * and sets dt and f_dt accordingly
	 */
	void CalcDT(const int& p_startTime, const int& p_endTime);

	int timeNow, timeLast, dt;
	float f_dt;
	int timeIncrement, timeNext, timeLastReady;
};
