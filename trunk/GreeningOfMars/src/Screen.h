#pragma once

class CScreen
{
public:
	CScreen(void);
	virtual ~CScreen(void);

	virtual void Update(float f_dt) = 0;
	virtual void Draw() = 0;
	virtual void Load() = 0;
	virtual void Unload() = 0;
};
