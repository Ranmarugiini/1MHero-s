#include "stdafx.h"
#include "Player.h"
#include <exception>
#include <iostream>
#include <thread>
#include <chrono>

Player::Player()
	: rectPos(400, 500), // 初期位置を指定
	isJumping(false),
	velocityY(0.0),
	speed(300.0),
	fixedY(500.0) // 地面のY座標
{}

void Player::Initialize()
{
	// 必要な初期化コードをここに記述
}

void Player::Update()
{
	double mouseX = Cursor::PosF().x;
	double directionX = mouseX - rectPos.x;
	double directionXNormalized = (directionX != 0) ? directionX / std::abs(directionX) : 0;
	rectPos.x += directionXNormalized * speed * Scene::DeltaTime();

	if (isJumping)
	{
		velocityY += gravity * Scene::DeltaTime();
		rectPos.y += velocityY * Scene::DeltaTime();
	}

	if (rectPos.y >= fixedY)
	{
		rectPos.y = fixedY;
		isJumping = false;
		velocityY = 0.0;
	}

	if (MouseL.down() && !isJumping)
	{
		isJumping = true;
		velocityY = -350.0;
	}

	if (MouseL.down())
	{
		Attack();
	}

	for (auto& bullet : bullets)
	{
		bullet.update(Scene::DeltaTime());
	}

	bullets.remove_if([](const Bullet& bullet)
	{
		return bullet.isOffScreen();
	});

	HitCheck();
	if (NiinumaItika == 5)
	{

		// 左上位置 (20, 20) からテキストを描く
		font(U"Game Clear!").draw(20, 20);
		std::this_thread::sleep_for(std::chrono::seconds(3));
		//std::terminate();
	};
	Draw();
}

void Player::Attack()
{
	Vec2 BulletPos = rectPos;
	BulletPos.y += 25;
	Vec2 target = Cursor::PosF();
	Vec2 start = BulletPos;
	Vec2 direction = (target - start).setLength(300);
	bullets.push_back(Bullet(start, direction));
}

void Player::Draw()
{
	RectF(rectPos.x, rectPos.y, 40, 40).draw(Palette::Green);
	OZworld.resized(60).drawAt(rectPos.x+20, rectPos.y+10);
	

	for (const auto& bullet : bullets)
	{
		bullet.draw();
	}

	for (const auto& enemy : enemies)
	{
		enemy.draw();
	}
}

void Player::HitCheck()
{
	for (auto it = bullets.begin(); it != bullets.end();)
	{
		bool hit = false;
		for (auto enemyIt = enemies.begin(); enemyIt != enemies.end();)
		{
			if (enemyIt->hitBy(*it))
			{
				enemyIt = enemies.erase(enemyIt);
				hit = true;
				NiinumaItika++;
			}
			else
			{
				++enemyIt;
			}
		}

		if (hit)
		{
			it = bullets.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Player::addEnemy(const Vec2& pos)
{
	enemies.push_back(Enemy(pos));
}
