#pragma once

namespace Game
{
	// ウインドウモード設定
	constexpr bool kWindowModo = true;
	// ウインドウ名
	const char* const kTitleText = "ゲーム名";
	// ウインドウサイズ
	constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 720;
	constexpr int kScreenInterval = 10;

	// ゲームのステージサイズ
	constexpr int kStageUpperLimit = 100;
	constexpr int kStageLowerLimit = 620;

	// カラーモード
	constexpr int kColorDepth = 32;		// 32 or 16
};