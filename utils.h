#pragma once

void drawStage();
void drawMessage();
void drawBattle();

struct Disk
{
	float cx, cy;
	float radius;
	Disk(float x, float y, float r) { cx = x; cy = y; radius = r; }
	Disk() {}
};