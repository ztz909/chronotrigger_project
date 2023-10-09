#include "enemy.h"

void Enemy::draw()
{
	if (alive)
	{
		eplush.texture = "assets\\enemies\\impRed.png";
		eplush.outline_opacity = 0.0f;
		graphics::drawRect(pos_x, pos_y, enemy_w, enemy_h, eplush);
	}
}

void Enemy::update()
{
	if (hp <= 0)
	{
		alive = false;
	}
}
void Enemy::flinch()
{
	pos_x -= 5.0f;
}
void Enemy::flinchBack() 
{
	pos_x += 5.0f; 
}
int Enemy::enemyAttack(int php, int pdef, int patk)
{
	int damage = atk - pdef * pdef / 100;
	int futurephp = php - damage;
	return futurephp;
}