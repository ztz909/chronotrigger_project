#pragma once
#include "utils.h"
#include "gamething.h"
#include "Collidable.h"

class Inanimate : public GameObject, public Collidable
{
	float cx, cy;
	float rad;
public:
	void draw() override;
	void update() override;
	Inanimate(float x, float y, float r);
	Disk getCollisionHull() const override;
};