#include "Collidable.h"

Collidable::Collidable(float x, float y, float r)
{
	cx = x;
	cy = y;
	radius = r;
}

Collidable::~Collidable()
{
}
void Collidable::draw()
{
	graphics::Brush cush;
	cush.fill_opacity = 0.0f;
	cush.outline_opacity = 1.0f;
	graphics::drawDisk(cx, cy, radius, cush);
}

void Collidable::update()
{
}