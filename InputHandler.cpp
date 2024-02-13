#include"InputHandler.h"
#include "Novice.h"
ICommand* InputHandler::HandleInput() {
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}

	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}

	return nullptr;
}

void InputHandler::AssingMoveLeftCommand2PressKeyA() {
	ICommand* command = new LeftCommand();
	pressKeyA_ = command;
}

void InputHandler::AssingMoveRightCommand2PressKeyD() {
	ICommand* command = new RightCommand();
	pressKeyD_ = command;
}