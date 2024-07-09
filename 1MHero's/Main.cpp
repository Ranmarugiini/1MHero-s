# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include"Player.h"
#include <exception>
#include <iostream>
#include <thread>
#include <chrono>
void Main()
{// 警告を無効にする
	//15~44秒のループ
	AudioAsset::Register(U"BGM", U"example/DAISOUSA.mp3");

	Profiler::EnableAssetCreationWarning(false);

	TextureAsset::Register(U"OZworld", U"example\\OZworld.png");
	TextureAsset::Register(U"ENEMY", U"example\\Keisatu.png");
	TextureAsset::Register(U"SHOT1", U"example\\Dragon.png");
	TextureAsset::Register(U"SHOT2", U"example\\6.png");
	TextureAsset::Register(U"Haikei", U"example\\Haikei.jpg");

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
	AudioAsset(U"BGM").seekSamples(17);
	AudioAsset(U"BGM").play();
	while (System::Update())
	{
		ClearPrint();

		// ループが設定されているか
		Print << AudioAsset(U"BGM").isLoop();
		// ループ回数
		Print << AudioAsset(U"BGM").loopCount();
		// 曲全体
		Print << U"all: {:.1f} sec ({} samples)"_fmt(AudioAsset(U"BGM").lengthSec(), AudioAsset(U"BGM").samples());

		// 再生位置
		Print << U"play: {:.1f} sec ({} samples)"_fmt(AudioAsset(U"BGM").posSec(), AudioAsset(U"BGM").posSample());
//背景を描画
TextureAsset(U"Haikei").resized(800,600).draw();
		Print << Time::GetSec();

		player.Update();
		if (Time::GetSec() >60)
		{
			font(U"GameOver").drawAt(Scene::Center(), Palette::Red);

			std::this_thread::sleep_for(std::chrono::seconds(3));
			//std::terminate();
		}
	}
}
