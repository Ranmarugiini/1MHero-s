#include "stdafx.h"
#include "Player.h"

void Player::Initialize()
{// 四角形の初期位置を設定
	isJumping = false;
}

void Player::Update()
{	// マウスカーソルのX座標を取得
	double mouseX = Cursor::PosF().x;

	// 四角形の現在位置のX座標とマウスカーソルのX座標との差を計算
	double directionX = mouseX - rectPos.x;

	// X座標の方向ベクトルを計算（正規化）
	double directionXNormalized = (directionX != 0) ? directionX / std::abs(directionX) : 0;

	// X座標の更新（フレームごとの移動量を計算）
	rectPos.x += directionXNormalized * speed * Scene::DeltaTime();

	if (KeySpace.pressed() && !isJumping)
	{
		rectPos.y = -10.0;
		isJumping = true;
	}
	if (MouseL.pressed())
	{
		Player::Attack();
	}
	// 画面端を探知して速度をゼロに設定
	if (rectPos.x < 0)
	{
		rectPos.x = 0;
	}
	else if (position.x > 640) // 画面の幅を640
	{
		position.x = 640;
		velocity.x = 0;
	}

	if (position.y >= 400)
	{
		position.y = 400;
		isJumping = false;
	}
	// 四角形を描画
	RectF(rectPos, rectSize).draw(Palette::Skyblue);
}

void Player::Attack()
{


}
