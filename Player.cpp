#include"Player.h"
#include "Novice.h"
Player::Player() {
	Init();
}
void Player::Init() {
	pos_ = { 200.0f,200.0f };
	speed_ = 2.0f;
}
void Player::Update(){}
void Player::Draw() {
	//Novice::DrawEllipse(
	//	(int)pos_.x, (int)pos_.y,
	//	16, 16, 0.0f,
	//	WHITE, kFillModeSolid
	//);
	Novice::DrawBox((int)pos_.x, (int)pos_.y,
		32, 32, 0.0f, WHITE, kFillModeSolid);
}
void Player::MoveRight() {
	//this->pos_.x += this->speed_;
	pos_.x += speed_;
}
void Player::MoveLeft() {
	//this->pos_.x -= this->speed_;
	pos_.x -= speed_;
}

