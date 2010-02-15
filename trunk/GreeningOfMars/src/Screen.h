#pragma once

class Screen
{
public:
	Screen(void);
	virtual ~Screen(void);

	virtual void Update(float p_dt) = 0;
	virtual void Draw() = 0;
	virtual void Load() = 0;
	virtual void Unload() = 0;
};
