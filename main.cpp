#include <Novice.h>
#include <Vector2.h>
#include<stdio.h>
#include"InputHandler.h"
#include "Novice.h"
#include"Player.h"

const char kWindowTitle[] = "LE2D_15_タナカタイシ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Vector2 pos_ = {100.0f, 300.0f};
	//float speed_ = 2.0f;
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	InputHandler* inputHandler = new InputHandler();
	inputHandler->AssingMoveLeftCommand2PressKeyA();
	inputHandler->AssingMoveRightCommand2PressKeyD();


	ICommand* command_ = nullptr;
	Player* player = new Player();


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		command_ = inputHandler->HandleInput();

		if (command_) {
			command_->Exec(*player);
		}

		player->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
