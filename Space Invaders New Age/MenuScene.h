#pragma once
#include "GameScene.h"

class MenuScene : public GameScene
{
public:
	MenuScene() {}

	void initialize() override;
	void update(float in_dt) override;
};