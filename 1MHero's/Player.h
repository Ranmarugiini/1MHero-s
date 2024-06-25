#pragma once
#include <Siv3D.hpp>
#include "Bullet.h"
#include "Enemy.h"

class Player
{
public:
	// プレイヤーの画像
	const Texture OZworld{ U"example/OZworld.png" };

	Player(); // コンストラクタの宣言
	void Initialize();
	void Update();
	void Draw();
	void addEnemy(const Vec2& pos);
	int NiinumaItika = 0;
	// 基本サイズ 50 のフォントを作成
	const Font font{ 50 };
	Array<Bullet> bullets;
	Array<Enemy> enemies;
private:
	void Attack();
	void HitCheck();

	Vec2 rectPos; // プレイヤーの位置
	const Rect MRect{ 0, 0, 100, 100 }; // プレイヤーの矩形サイズを指定

	bool isJumping;
	double velocityY;
	double speed;
	double fixedY;
	const double gravity = 980.0;

};


