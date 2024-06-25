#pragma once
#include <Siv3D.hpp>
#include "Bullet.h"

class Enemy
{
public:
	Enemy(Vec2 pos);
	void update(double deltaTime);
	void draw() const;
	bool hitBy(const Bullet& bullet) const;

private:
	Vec2 m_position;
};



