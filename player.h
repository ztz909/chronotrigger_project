#pragma once

#include "gamething.h"
#include "Collidable.h"
#include "utils.h"
#include "enemy.h"
#include <string>

class Playable_character: public GameObject, public Collidable
{	
private:
	float pos_x = 0.0f, pos_y = 0.0f, radius = 70.0f;
	float speed = 2.5f;
	float player_w = 50.0f;
	float player_h = 150.0f;
	int hp = 250, atk = 15, def = 5, spatk = 20;
	graphics::Brush plush;
	graphics::Brush plush_col;
	std::string png_path;
	int direction = 0;
	bool battle = false;
	bool turn = false;
	bool moveup = true, movedown = true, moveright = true, moveleft = true;
public:
	Playable_character(float x, float y);
	Playable_character() {};
	~Playable_character();
	Disk getCollisionHull() const override; 
	int getDir() { return direction; }
	float getX() { return pos_x; }
	float getY() { return pos_y; }
	float getRad() { return radius; }
	void lock_moveup() { moveup = false; }
	void lock_movedown() { movedown = false; }
	void lock_moveleft() { moveleft = false; }
	void lock_moveright() { moveright = false; }
	void unlock_moveup() { moveup = true; }
	void unlock_movedown() { movedown = true; }
	void unlock_moveleft() { moveleft = true; }
	void unlock_moveright() { moveright = true; }
	void setX(float x) { pos_x = x; }
	void setY(float y) { pos_y = y; }
	void setDefaultSize() { player_h = 150.0f; player_w = 50.0f; }
	void setMapSize() { player_h = 75.0f; player_w = 25.0f; }
	void draw() override;
	void update() override;
	bool getTurn() { return turn; }
	void setTurn(bool t) {turn = t;}
	int getAtk() { return atk; }
	int getDef() { return def; }
	std::string getHp()
	{
		return std::to_string(hp);
	}
	void setHp(int php) { hp = php; }
	void attack(Enemy* e);
	void sp_attack(Enemy* e);
	void setBattle(bool what) {
		battle = what; 
		png_path = "assets\\main_chars\\cronofight.png";
	}
	int getHPnum() { return hp; }
	void flinch() { pos_x += 5.0f; }
	void flinch_back() { pos_x -= 5.0f; }
};