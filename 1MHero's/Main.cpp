# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include"Player.h"
#include <exception>
#include <iostream>
#include <thread>
#include <chrono>
void Main()
{// 警告を無効にする
	Profiler::EnableAssetCreationWarning(false);

	TextureAsset::Register(U"OZworld", U"example\\OZworld.png");
	TextureAsset::Register(U"ENEMY", U"example\\唾奇.png");
	TextureAsset::Register(U"SHOT1", U"example\\Dragon.png");
	TextureAsset::Register(U"SHOT2", U"example\\6.png");
	
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
