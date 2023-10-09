#pragma once

#include "gamething.h"
#include "utils.h"

class Enemy : public GameObject
{
private:
	float pos_x = 350.0f, pos_y = 500.0f;
	float enemy_w = 50.0f;
	float enemy_h = 110.0f;
	int hp=100;
	int atk=80;
	int def = 25;
	bool alive = true;
	graphics::Brush eplush;
	std::string png_path = "assets\\enemies\\impRed.png";
public:
	Enemy(int health, int attack, int defense, float x, float y) { hp = health; atk = attack; def = defense; pos_x = x; pos_y = y; }
	~Enemy() {}
	void draw() override;
	void update() override;
	std::string getHPstring() { return std::to_string(hp); }
	int getHp() { return hp; }
	int getAtk() { return atk; }
	int getDef() { return def; }
	void setHp(int hpNew) { this->hp = hpNew; }
	bool status() { return alive; }
	void flinch();
	void flinchBack();
	int enemyAttack(int php, int pdef, int patk);
	bool defeated() { if (hp <= 0) return true; return false; }
};