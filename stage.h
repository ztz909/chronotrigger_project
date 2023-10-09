#pragma once
#include "gamething.h"

class Stage :public GameObject
{
public:
	void draw() override;
	void update() override;
	Stage() {}
	~Stage() {}
private:
	graphics::Brush stush;
};