#include "Inanimate.h"
#include "graphics.h"

Disk Inanimate::getCollisionHull() const
{
	Disk disk;
	disk.cx = cx;
	disk.cy = cy;
	disk.radius = rad;
	return disk;
}

void Inanimate::draw()
{
	graphics::Brush br;
	br.fill_opacity = 0.0f;
	br.outline_opacity = 0.0f;
	float x = getCollisionHull().cx;
	float y = getCollisionHull().cy;
	float r = getCollisionHull().radius;
	graphics::drawDisk(x, y, r, br);
}

void Inanimate::update()
{
}

Inanimate::Inanimate(float x, float y, float r)
{
	cx = x;
	cy = y;
	rad = r;
}

