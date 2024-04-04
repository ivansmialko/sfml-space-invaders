#include "Application.h"
#include "MenuScene.h"
#include "ShapeObject.h"
#include "SpriteObject.h"

void MenuScene::initialize()
{
	ShapeObject* circle_shape_object = new ShapeObject();
	circle_shape_object->init(ShapeObject::EST_SHAPE_CIRCLE);
	circle_shape_object->setShapeParam(ShapeObject::ECSP_RADIUS, 200.f);
	circle_shape_object->setFillColor(150, 50, 150);
	circle_shape_object->setX(50.0);
	circle_shape_object->setY(50.0);

	ShapeObject* circle2 = new ShapeObject();
	circle2->init(ShapeObject::EST_SHAPE_CIRCLE);
	circle2->setShapeParam(ShapeObject::ECSP_RADIUS, 50.f);
	circle2->setFillColor(50, 50, 50);
	circle2->setX(150.0);
	circle2->setY(150.0);

	SpriteObject* simple_image = new SpriteObject("images.jpg");

	addChild(simple_image);
	addChild(circle_shape_object);
	addChild(circle2);
}

void MenuScene::update(float in_dt)
{
	
}
