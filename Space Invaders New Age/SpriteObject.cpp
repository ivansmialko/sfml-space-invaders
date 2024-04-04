#include "SpriteObject.h"
#include "Application.h"

SpriteObject::SpriteObject(std::string in_texture_path)
{
	_texture = new sf::Texture();
	_texture->loadFromFile(in_texture_path);

	_sprite = new sf::Sprite();
	_sprite->setTexture(*_texture);
}

SpriteObject::~SpriteObject()
{
	if(_texture)
		delete _texture;

	if(_sprite)
		delete _sprite;
}

void SpriteObject::setX(double in_x)
{
	if(!_sprite)
		return;

	GameObject::setX(in_x);
	_sprite->setPosition(in_x, _sprite->getPosition().y);
}

void SpriteObject::setY(double in_y)
{
	if(!_sprite)
		return;

	GameObject::setY(in_y);
	_sprite->setPosition(_sprite->getPosition().x, in_y);
}

void SpriteObject::render()
{
	GameObject::render();
	Application::getInstance()->render(_sprite);
}
