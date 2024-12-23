#pragma once
#include <vector2.h>
#include "IScene.h"

/// <summary>
/// ISceneクラスを継承したStageSceneを宣言
/// </summary>
class StageScene : public IScene
{
public://メンバ関数

	///初期化処理
	void Initialize() override;

	///更新処理
	void Update(char* keys, char* preKeys) override ;

	///描画処理
	void Draw() override;

private:
	//自機の座標
	Vector2 positon_ = { 640, 360 };

	//弾の座標
	Vector2 shotPositon_ = { 0,0 };

	//自機のスピード
	float positonSpeed_ = 4.0f;

	//弾のスピード
	float shotSpeed_ = 10.0f;

	//弾のフラグ
	bool isBulletShot_ = false;
};

