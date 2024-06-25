#include "stdafx.h"
#include "Enemy.h"
Enemy::Enemy(Vec2 pos)
	: m_position(pos) {}

void Enemy::update(double deltaTime)
{
	// 必要に応じて敵の動作を追加

}

void Enemy::draw() const
{
	RectF(m_position, 40, 40).draw(Palette::Blue);
}

bool Enemy::hitBy(const Bullet& bullet) const
{
	return RectF(m_position, 40, 40).intersects(Circle(bullet.getPosition(), 5));
}
