#pragma once
#include"Vector2.h"
class Player {
public:
	Player();

	void Init();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();
	
private:
	Vector2 pos_;
	float speed_;
};
