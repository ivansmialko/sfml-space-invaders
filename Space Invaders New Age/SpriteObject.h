#pragma once
#include "GameObject.h"
#include "SFML/Graphics.hpp"

class SpriteObject : public GameObject
{
private:
	sf::Sprite* _sprite{ nullptr };
	sf::Texture* _texture{ nullptr };

public:
	SpriteObject() {};
	SpriteObject(std::string in_texture_path);
	~SpriteObject();

	virtual void setX(double in_x) override;
	virtual void setY(double in_y) override;
	virtual void render() override;
};