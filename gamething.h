#pragma once
#include "graphics.h"

class GameObject
{
public:
	GameObject() {};
	~GameObject() {};
	virtual void draw() = 0;
	virtual void update() = 0;
};