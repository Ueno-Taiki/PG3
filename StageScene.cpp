#include "StageScene.h"

void StageScene::Initialize() {}

void StageScene::Update(char* keys, char* preKeys) {
	//自機移動
	if (keys[DIK_W]) {
		positon_.y -= positonSpeed_;
	}
	if (keys[DIK_S]) {
		positon_.y += positonSpeed_;
	}
	if (keys[DIK_D]) {
		positon_.x += positonSpeed_;
	}
	if (keys[DIK_A]) {
		positon_.x -= positonSpeed_;
	}

	// 弾を発射
	if (isBulletShot_ == false) {
		if (!preKeys[DIK_RETURN] && keys[DIK_RETURN]) { // スペースを押すと玉を発射する
			isBulletShot_ = true;
			shotPositon_.x = positon_.x;
			shotPositon_.y = positon_.y;
		}
	}
	if (isBulletShot_) {
		shotPositon_.y = shotPositon_.y - shotSpeed_;
		if (shotPositon_.y <= 0) {
			isBulletShot_ = false;
		}
	}

	//スペースキーを押した瞬間
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == false) {
		//シーンをCLEARに変える
		sceneNo = CLEAR;
	}
}

void StageScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Stage Scene");
	Novice::ScreenPrintf(0, 30, "Push Space");

	//自機を描画
	Novice::DrawEllipse((int)positon_.x, (int)positon_.y, 20, 20, 0.0f, WHITE, kFillModeSolid);

	//弾を描画
	if (isBulletShot_) {
		Novice::DrawTriangle((int)shotPositon_.x , (int)shotPositon_.y - 8, (int)shotPositon_.x - 8, (int)shotPositon_.y + 8,
			(int)shotPositon_.x + 8, (int)shotPositon_.y + 8, RED, kFillModeSolid);
	}
}
