#include "ShapeObject.h"
#include "Application.h"

const double ShapeObject::DEFAULT_RADIUS = 50.0;

void ShapeObject::initCircle()
{
	_shape = new sf::CircleShape();
}

ShapeObject::~ShapeObject()
{
	if (_shape)
	{
		delete _shape;
	}
}

void ShapeObject::init(EShapeType in_shape_type)
{
	_shape_type = in_shape_type;

	switch (_shape_type)
	{
		case EST_SHAPE_UNKNOWN:
		{
			return;
		} break;
		case EST_SHAPE_CIRCLE:
		{
			initCircle();
		}
	}
}

void ShapeObject::setShapeParam(ECircleShapeParam in_param, double in_value)
{
	if(!_shape)
		return;

	if(_shape_type != EST_SHAPE_CIRCLE)
		return;

	sf::CircleShape* circle_shape = static_cast<sf::CircleShape*>(_shape);

	switch (in_param)
	{
		case ECSP_RADIUS:
		{
			circle_shape->setRadius(static_cast<float>(in_value));
		} break;
		case ECSP_POINT_COUNT:
		{
			circle_shape->setPointCount(static_cast<size_t>(in_value));
		}break;
		default:
		{}
	}
}

void ShapeObject::setFillColor(char in_r, char in_g, char in_b, char in_a /*= 255*/)
{
	if(!_shape)
		return;

	_shape->setFillColor(sf::Color(in_r, in_g, in_b, in_a));
}

void ShapeObject::setOutlineColor(char in_r, char in_g, char in_b, char in_a /*= 255*/)
{
	if (!_shape)
		return;

	_shape->setOutlineColor(sf::Color(in_r, in_g, in_b, in_a));
}

void ShapeObject::setX(double in_x)
{
	if(!_shape)
		return;

	GameObject::setX(in_x);
	_shape->setPosition(in_x, _shape->getPosition().y);
}

void ShapeObject::setY(double in_y)
{
	if (!_shape)
		return;

	GameObject::setY(in_y);
	_shape->setPosition(_shape->getPosition().x, in_y);
}

void ShapeObject::render()
{
	GameObject::render();
	Application::getInstance()->render(_shape);
}

