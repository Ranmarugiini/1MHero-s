#pragma once
#include <Siv3D.hpp>

class Bullet
{
public:
	// Siv3D くん（Siv3D の公式マスコットキャラクター）の画像
	const Texture Dragon{ U"example/Dragon.png" };
	Bullet(Vec2 pos, Vec2 vel);

	// コピーコンストラクタとコピー代入演算子を削除
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;

	// ムーブコンストラクタとムーブ代入演算子をデフォルトで有効化
	Bullet(Bullet&&) = default;
	Bullet& operator=(Bullet&&) = default;

	void update(double deltaTime);
	void draw() const;
	bool isOffScreen() const;
	Vec2 getPosition() const;

	Vec2 m_position;
	Vec2 m_velocity;
};


