#include "player.h"

Playable_character::Playable_character(float x, float y)
{
	png_path = "assets\\main_chars\\cronofront.png";
	pos_x = x;
	pos_y = y;
}
Playable_character::~Playable_character()
{
}
Disk Playable_character::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = 49.0f;
	return disk;
}
void Playable_character::draw()
{
	plush.texture = png_path;
	plush_col.fill_opacity = 0.0f;
	plush.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, player_w, player_h, plush);
	Disk hull = getCollisionHull();
	graphics::Brush br;
	br.fill_opacity = 0.0f;
	br.outline_opacity = 0.0f;
	graphics::drawDisk(hull.cx, hull.cy, hull.radius,br);
}
void Playable_character::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_W) && moveup && !battle)
	{
		png_path = "assets\\main_chars\\cronoback.png";
		direction = 1;
		pos_y -= speed;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S) && movedown && !battle)
	{
		png_path = "assets\\main_chars\\cronofront.png";
		direction = 2;
		pos_y += speed;
	}
	if (graphics::getKeyState(graphics::SCANCODE_A) && moveleft && !battle)
	{
		png_path = "assets\\main_chars\\cronoleft.png";
		direction = 3;
		pos_x -= speed;
	}
	if (graphics::getKeyState(graphics::SCANCODE_D) && moveright && !battle)
	{
		png_path = "assets\\main_chars\\cronoright.png";
		direction = 4;
		pos_x += speed;
	}
}

void Playable_character::attack(Enemy* e)
{
	int damage = atk - atk * e->getDef() / 100;
	e->setHp(e->getHp() - damage);
}
void Playable_character::sp_attack(Enemy* e)
{
	e->setHp(e->getHp() - spatk);
}