#pragma once
#include<Siv3D.hpp>
class Player
{
public:
	Vec2 rectPos;
	const Vec2 rectSize;
	const double fixedY;
	const double speed;
	bool isJumping=false;

	Player(): rectPos(400, 300), rectSize(50, 50), fixedY(300), speed(500.0)
	{
	}

	void Initialize();
	void Update();
	void Attack();
};

