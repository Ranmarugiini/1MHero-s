#include "Bullet.h"

Bullet::Bullet(Vec2 pos, Vec2 vel)
	: m_position(pos), m_velocity(vel) {}

void Bullet::update(double deltaTime)
{
	m_position += m_velocity * deltaTime;
}

void Bullet::draw() const
{
	//Dragon.mirrored().drawAt(m_position.x, m_position.y);
	//Circle(m_position, 5).draw(Palette::Red);
	TextureAsset(U"SHOT1").mirrored().resized(70).drawAt(m_position);
}

bool Bullet::isOffScreen() const
{
	return !RectF(Scene::Rect()).intersects(Circle(m_position, 20));
}

Vec2 Bullet::getPosition() const
{
	return m_position;
}

