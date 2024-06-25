# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include"Player.h"
#include <exception>
#include <iostream>
#include <thread>
#include <chrono>
void Main()
{
	// 基本サイズ 50 のフォントを作成
	const Font font{ 50 };
	Player player;
	player.Initialize();

	// 敵を追加
	player.addEnemy(Vec2(500, 500));
	player.addEnemy(Vec2(550, 500));
	player.addEnemy(Vec2(600, 500));
	player.addEnemy(Vec2(650, 500));
	player.addEnemy(Vec2(700, 500));

	while (System::Update())
	{
		Print << Time::GetSec();

		player.Update();
		if (Time::GetSec() >60)
		{
			// 左上位置 (20, 20) からテキストを描く
			font(U"Game Over!").draw(20, 20);
			std::this_thread::sleep_for(std::chrono::seconds(3));
			//std::terminate();
		}
	}
}
