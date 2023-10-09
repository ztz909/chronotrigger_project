#include "graphics.h"
#include "gamething.h"
#include "utils.h"
#include "player.h"
#include "Collidable.h"
#include "Inanimate.h"
#include "enemy.h"
#include <string>
#include <cmath>
#define COLS_NUM 12

struct Chrono
{
	float window_width = 1100;
	float window_height =750;
	float canvas_width = 1064;
	float canvas_height = 896;
	int stage_id=0;
	std::string message;
	std::string activeStage;
	bool displayMessage = false;
	bool battle = false;
	bool ending = false;
	Playable_character * crono = nullptr;
	Enemy* imp1 = nullptr;
	Inanimate* c[COLS_NUM];
	std::string battleMessage;
	void setMessage(std::string msg)
	{
		message = msg;
	}
	void setActiveStage()
	{
		switch (stage_id)
		{
		case 1:
		{
			activeStage = "assets\\rooms\\cronosroom1.png";
			break;
		}
		case 2:
		{
			activeStage = "assets\\rooms\\cronoshouse2.png";
			break;
		}
		case 3:
		{
			activeStage = "assets\\rooms\\trucemap3.png";
			break;
		}
		case 4:
		{
			activeStage = "assets\\rooms\\leenesquare4.png";
			break;
		}
		case 5:
		{
			activeStage = "assets\\rooms\\gatoroom6.png";
			break;
		}
		case 6:
		{
			activeStage = "assets\\rooms\\lucaexhibit7.png";
			break;
		}
		case 7:
		{
			activeStage = "assets\\rooms\\past8.png";
			break;
		}
		case 8:
		{
			activeStage = "assets\\rooms\\GameOver.png";
			break;
		}
		case 9:
		{
			activeStage = "assets\\rooms\\EndScreen.png";
			break;
		}
		}
	}
	void init()
	{
		stage_id = 0;
		activeStage = "assets\\completeTitleScreen.png";
		graphics::setFont("assets\\Chrono Trigger Monospaced.ttf");
		graphics::playMusic("assets\\music&noise\\EndOfTime.mp3",0.2f,true,0);
		for (int i = 0; i < COLS_NUM; i++)
		{
			c[i] = nullptr;
		}
	}
	bool checkCollision()
	{
		bool check = false;
		if (!crono)
			return check;
		Disk d1 = crono->getCollisionHull();
		for (int i = 0; i < COLS_NUM - 1; i++)
		{
			
			if (c[i])
			{
				Disk d2 = c[i]->getCollisionHull();
				float dx = d1.cx - d2.cx;
				float dy = d1.cy - d2.cy;
				if (sqrt(dx * dx + dy * dy) <= d1.radius + d2.radius)
					check = true;
			}
			else
				return check;
		}
		return check;
	}
	bool checkSingleCollision(Inanimate* in)
	{
		bool check = false;
		Disk d1 = crono->getCollisionHull();
		Disk d2 = in->getCollisionHull();
		float dx = d1.cx - d2.cx;
		float dy = d1.cy - d2.cy;
		if (crono && in)
		{
			if (sqrt(dx * dx + dy * dy) <= d1.radius + d2.radius)
				check =  true;
		}
		return check;
	}
	void loadCronoRoom()
	{
		c[0] = new Inanimate(canvas_width - canvas_width / 3 + 75.0f, canvas_height / 2 + 25.0f, 150.0f);
		c[1] = new Inanimate(660.0f, 680.0f, 175.0f);
		c[2] = new Inanimate(420.0f, 650.0f, 40.0f);
		c[3] = new Inanimate(75.0f, 900.0f, 100.0f);
		c[4] = new Inanimate(425.0f, 240.0f, 125.0f);
		c[5] = new Inanimate(75.0f, 480.0f, 125.0f);
		c[6] = new Inanimate(75.0f, 600.0f, 125.0f);
		c[7] = new Inanimate(200.0f, 240.0f, 125.0f);
		c[8] = new Inanimate(600.0f, 240.0f, 125.0f);
		c[9] = new Inanimate(75.0f, 700.0f, 125.0f);
		c[10] = new Inanimate(250.0f, 900.0f, 100.0f);
		c[11] = new Inanimate(420.0f, 770.0f, 65.0f);
	}
	void loadCronoHouse()
	{
		for (int i = 0; i < COLS_NUM; i++)
		{
			if (c[i])
				delete c[i];
		}
		c[0] = new Inanimate(600.0f, 250.0f, 150.0f);
		c[1] = new Inanimate(1020.0f,  680.0f, 75.0f);
		c[2] = new Inanimate(1020.0f, 500.0f, 75.0f);
		c[3] = new Inanimate(250.0f, 900.0f, 100.0f);
		c[4] = new Inanimate(250.0f,  240.0f, 125.0f);
		c[5] = new Inanimate(900.0f, 180.0f, 150.0f);
		c[6] = new Inanimate(100.0f, 450.0f, 125.0f);
		c[7] = new Inanimate(400.0f,  900.0f, 125.0f);
		c[8] = new Inanimate(920.0f,  879.0f, 80.0f);
		c[9] = new Inanimate(100.0f, 700.0f, 125.0f);
		c[10] = new Inanimate(550.0f, 900.0f, 100.0f);
		c[11] = new Inanimate(732.0f, 878.0f, 65.0f);
	}
	void loadTruce()
	{
		for (int i = 0; i < COLS_NUM; i++)
		{
			if (c[i])
				delete c[i];
		}
		c[0] = new Inanimate(380.0f, 150.0f, 100.0f);
		c[1] = new Inanimate(100.0f, 680.0f, 100.0f);
		c[2] = new Inanimate(250.0f, 500.0f, 100.0f);
		c[3] = new Inanimate(250.0f, 900.0f, 100.0f);
		c[4] = new Inanimate(250.0f, 240.0f, 125.0f);
		c[5] = new Inanimate(850.0f, 300.0f, 250.0f);
		c[6] = new Inanimate(100.0f, 450.0f, 125.0f);
		c[7] = new Inanimate(400.0f, 900.0f, 125.0f);
		c[8] = new Inanimate(920.0f, 879.0f, 80.0f);
		c[9] = new Inanimate(560.0f, 680.0f, 175.0f);
		c[10] = new Inanimate(550.0f, 900.0f, 100.0f);
		c[11] = new Inanimate(570.0f, 110.0f, 65.0f);
	}
	void loadLeeneSquare()
	{
		for (int i = 0; i < COLS_NUM; i++)
		{
			if (c[i])
				delete c[i];
		}
		c[0] = new Inanimate(250.0f, 170.0f, 170.0f);
		c[1] = new Inanimate(100.0f, 500.0f, 100.0f);
		c[2] = new Inanimate(100.0f, 750.0f, 100.0f);
		c[3] = new Inanimate(900.0f, 700.0f, 100.0f);
		c[4] = new Inanimate(250.0f, 900.0f, 100.0f);
		c[5] = new Inanimate(900.0f, 450.0f, 100.0f);
		c[6] = new Inanimate(500.0f, 900.0f, 100.0f);
		c[7] = new Inanimate(700.0f, 900.0f, 100.0f);
		c[8] = new Inanimate(900.0f, 900.0f, 100.0f);
		c[9] = new Inanimate(809.0f, 180.0f, 170.0f);
		c[10] = new Inanimate(250.0f, 900.0f, 100.0f);
		c[11] = new Inanimate(550.0f, 65.0f, 65.0f);
	}
	void loadPast()
	{
		for (int i = 0; i < COLS_NUM; i++)
		{
			if (c[i])
				delete c[i];
		}
		c[0] = new Inanimate(100.0f, 250.0f, 100.0f);
		c[1] = new Inanimate(100.0f, 500.0f, 100.0f);
		c[2] = new Inanimate(100.0f, 750.0f, 100.0f);
		c[3] = new Inanimate(100.0f, 950.0f, 100.0f);
		c[4] = new Inanimate(250.0f, 900.0f, 100.0f);
		c[5] = new Inanimate(450.0f, 900.0f, 125.0f);
		c[6] = new Inanimate(100.0f, 600.0f, 125.0f);
		c[7] = new Inanimate(100.0f, 240.0f, 125.0f);
		c[8] = new Inanimate(100.0f, 240.0f, 125.0f);
		c[9] = new Inanimate(100.0f, 700.0f, 125.0f);
		c[10] = new Inanimate(250.0f, 900.0f, 100.0f);
		c[11] = new Inanimate(550.0f, 65.0f, 65.0f);
	}
};
void draw()
{
	Chrono* chrono = (Chrono*)(graphics::getUserData());
	drawStage();
	drawMessage();
	if (chrono->crono && !chrono->ending)
		chrono->crono->draw();
	if (chrono->imp1 && !chrono->ending)
		chrono->imp1->draw();
	for (int i = 0; i < COLS_NUM; i++)
	{
		if (chrono->c[i])
			chrono->c[i]->draw();
	}
	if (chrono->battle)
		drawBattle();
}
void drawBattle()
{
	Chrono* chrono = (Chrono*)(graphics::getUserData());
	if (chrono->battle)
	{
		graphics::Brush bplush;
		bplush.outline_opacity = 0.0f;
		bplush.texture = "assets\\defaultdialogbox.png";
		std::string crono_hp = "Crono "+chrono->crono->getHp();
		std::string imp_hp = "Boss "+chrono->imp1->getHPstring();
		if (chrono->crono->getHPnum() > 0 && !chrono->imp1->defeated() && !chrono->ending)
		{
			graphics::drawRect(500.0f, 90.0f, 420.0f, 100.0f, bplush);
			graphics::drawText(300.0f, 65.0f, 35.0f, crono_hp, bplush);
		}
		if (chrono->imp1->getHp()>=0 && !chrono->ending)
			graphics::drawText(300.0f, 95.0f, 35.0f, imp_hp, bplush);
	}
}
void drawStage()
{
	Chrono* chrono = (Chrono*)(graphics::getUserData());
	graphics::Brush bruh;
	bruh.fill_opacity = 1.0f;
	bruh.outline_opacity = 0.0f;
	bruh.texture = chrono->activeStage;
	graphics::drawRect(chrono->canvas_width/2,chrono->canvas_height/2, chrono->canvas_width, chrono->canvas_height ,bruh);
}
void drawMessage()
{
	Chrono* chrono = (Chrono*)(graphics::getUserData());
	graphics::Brush bruh1;
	bruh1.outline_opacity = 0.0f;
	bruh1.texture = "assets\\defaultdialogbox.png";
	if (chrono->displayMessage)
	{
		graphics::drawRect(chrono->canvas_width / 2, chrono->canvas_height-(chrono->canvas_height/8), chrono->canvas_width, chrono->canvas_height / 4, bruh1);
		graphics::drawText(chrono->canvas_width/40, chrono->canvas_height- (chrono->canvas_height / 5.5), 35.0f ,chrono->message, bruh1);
	}
}

void battleUpdate()
{
	Chrono* chrono = (Chrono*)(graphics::getUserData());
	if (!chrono->crono->getTurn() && chrono->imp1->getHp()>=0)
	{
		chrono->imp1->flinchBack();
		int player_hp = chrono->imp1->enemyAttack(chrono->crono->getHPnum(), chrono->crono->getDef(), chrono->crono->getAtk());
		chrono->crono->setHp(player_hp);
		graphics::playSound("assets\\music&noise\\attack.wav", 0.2f, false);
		chrono->crono->setTurn(true);
		chrono->crono->flinch();
	}
	else if (chrono->crono->getTurn() && chrono->imp1->getHp() >= 0 && chrono->crono->getHPnum() >= 0 &&  graphics::getKeyState(graphics::SCANCODE_W))
	{
		chrono->crono->attack(chrono->imp1);
		graphics::playSound("assets\\music&noise\\attack_alt.wav", 0.2f, false);
		chrono->crono->setTurn(false);
		chrono->imp1->flinch();
	}
	else if (chrono->crono->getTurn()&& chrono->imp1->getHp()>=0 && chrono->crono->getHPnum()>=0 && graphics::getKeyState(graphics::SCANCODE_S))
	{
		chrono->crono->sp_attack(chrono->imp1);
		graphics::playSound("assets\\music&noise\\burst.wav", 0.2f, false);
		chrono->crono->setTurn(false);
		chrono->imp1->flinch();
	}
}
void update(float ms)
{
	Chrono* chrono = (Chrono*)(graphics::getUserData());
	if (chrono->crono)
		chrono->crono->update();
	if (chrono->imp1)
		chrono->imp1->update();
	if (chrono->battle)
		battleUpdate();
	if ((chrono->crono) && chrono->checkCollision())
	{
		if (chrono->crono->getDir() == 1)
		{
			chrono->crono->lock_moveup();
			chrono->crono->setY(chrono->crono->getY() + 5.0f);
			chrono->crono->unlock_movedown();
		}
		else if (chrono->crono->getDir() == 2)
		{
			chrono->crono->lock_movedown();
			chrono->crono->setY(chrono->crono->getY() - 5.0f);
			chrono->crono->unlock_moveup();
		}
		else if (chrono->crono->getDir() == 3)
		{
			chrono->crono->lock_moveleft();
			chrono->crono->setX(chrono->crono->getX() + 5.0f);
			chrono->crono->unlock_moveright();
		}
		else if (chrono->crono->getDir() == 4)
		{
			chrono->crono->lock_moveright();
			chrono->crono->setX(chrono->crono->getX() - 5.0f);
			chrono->crono->unlock_moveleft();
		}
	}
	else if (chrono->crono)
	{
		chrono->crono->unlock_moveup();
		chrono->crono->unlock_moveleft();
		chrono->crono->unlock_moveright();
		chrono->crono->unlock_movedown();
	}
	if (chrono->imp1)
		chrono->imp1->update();
	if (chrono->stage_id == 0)
	{
		if (graphics::getKeyState(graphics::SCANCODE_SPACE))
		{
			chrono->setMessage("WASD to move/combat, PRESS W TO BEGIN");
			chrono->displayMessage = true;
			chrono->stage_id = 1;
		}
	}
	if (chrono->stage_id == 1)
	{
		if (graphics::getKeyState(graphics::SCANCODE_W))
		{
			chrono->setActiveStage();
			chrono->setMessage("Good morning sleepyhead! You'll be late to the fair.");
		}
	}
	if (graphics::getKeyState(graphics::SCANCODE_SPACE) && chrono->activeStage == "assets\\rooms\\cronosroom1.png")
	{
		graphics::playMusic("assets\\music&noise\\peacefuldays.mp3", 0.2f, true, 0);
		chrono->displayMessage = false;
		chrono->crono = new Playable_character(chrono->canvas_width/2, chrono->canvas_height/2);
		chrono->loadCronoRoom();
		chrono->crono->setDefaultSize();
	}
	if (chrono->stage_id == 1)
	{
		if (chrono->crono && chrono->checkSingleCollision(chrono->c[11]))
		{
			chrono->stage_id = 2;
			chrono->setActiveStage();
			chrono->loadCronoHouse();
			chrono->crono->setX(750.0f);
			chrono->crono->setY(450.0f);
			chrono->crono->setDefaultSize();
		}
	}
	if (chrono->stage_id == 2)
	{
		if (chrono->crono && chrono->checkSingleCollision(chrono->c[11]))
		{
			chrono->stage_id = 3;
			chrono->setActiveStage();
			chrono->loadTruce();
			chrono->crono->setX(400.0f);
			chrono->crono->setY(400.0f);
			chrono->crono->setMapSize();
		}
	}
	if (chrono->stage_id == 3)
	{
		if (chrono->crono && chrono->checkSingleCollision(chrono->c[11]))
		{
			chrono->stage_id = 4;
			chrono->setActiveStage();
			chrono->loadLeeneSquare();
			chrono->crono->setX(700.0f);
			chrono->crono->setY(700.0f);
			chrono->crono->setMapSize();
		}
	}
	if (chrono->stage_id == 4)
	{
		if (chrono->crono && chrono->checkSingleCollision(chrono->c[11]))
		{
			chrono->stage_id = 7;
			chrono->setActiveStage();
			chrono->loadPast();
			chrono->displayMessage = true;
			graphics::playMusic("assets\\music&noise\\battle.mp3", 0.2f, true, 0);
			chrono->setMessage("Crono, our protagonist found himself through a portal back in time");
			chrono->crono->setX(600.0f);
			chrono->crono->setY(450.0f);
			chrono->crono->setDefaultSize();
			chrono->crono->lock_movedown();
			chrono->crono->lock_moveup();
			chrono->crono->lock_moveleft();
			chrono->crono->lock_moveright();
			chrono->crono->setBattle(true);
		}
	}
	if (chrono->stage_id == 7 && graphics::getKeyState(graphics::SCANCODE_SPACE) && !chrono->battle)
	{
		chrono->battle = true;
		chrono->imp1 = new Enemy(100, 35, 25, 350.0f, 450.0f);
		chrono->setMessage("Pick command with WS: W attack S special");
	}
	if (chrono->battle)
	{
		if (chrono->imp1->defeated())
		{
			chrono->stage_id = 9;
			chrono->setActiveStage();
			chrono->displayMessage = false;
			if (!chrono->ending)
				graphics::playMusic("assets\\music&noise\\ending.mp3", 0.2f, true, 0);
			chrono->ending = true;
		}
		if (chrono->crono->getHPnum() <= 0)
		{
			chrono->stage_id = 8;
			chrono->setActiveStage();
			if (!chrono->ending)
				graphics::playMusic("assets\\music&noise\\gameover.mp3", 0.2f, true, 0);
			chrono->displayMessage = false;
			chrono->ending = true;
		}
	}
}
int main()
{
	Chrono chrono;
	graphics::createWindow(chrono.window_width, chrono.window_height, "Chrono Trigger");
	chrono.init();
	graphics::setUserData(&chrono);
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);
	graphics::setCanvasSize(chrono.canvas_width, chrono.canvas_height);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
	graphics::startMessageLoop();
	graphics::destroyWindow();
	return 0;
}