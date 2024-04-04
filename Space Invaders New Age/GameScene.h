#pragma once
#include "GameObject.h"

class GameScene : public GameObject
{
public:
	GameScene();

	virtual void initialize() = 0;
	virtual void update(float in_dt) = 0;
};