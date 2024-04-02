#include <SFML/Graphics.hpp>
#include "Application.h"

#include "GameScene.h"
#include "ShapeObject.h"
#include "GameObject.h"

int main()
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

	GameScene* main_game_scene = new GameScene();
	main_game_scene->addChild(circle_shape_object);
	main_game_scene->addChild(circle2);

	Application::getInstance()->setGameScene(main_game_scene);
	Application::getInstance()->createWindow(sf::VideoMode(500, 500), std::string("Space Invaders New Age"));
	Application::getInstance()->start();
	return 0;
}