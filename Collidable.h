#pragma once
#include "gamething.h"
#include "graphics.h"
#include "utils.h"

class Collidable :public GameObject
{
	float cx, cy, radius = 0.0f;
public:
	Collidable() {};
	Collidable(float x, float y, float r);
	~Collidable();
	virtual Disk getCollisionHull() const = 0;
	void draw() override;
	void update() override;
};