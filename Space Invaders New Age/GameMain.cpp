#include <SFML/Graphics.hpp>
#include "Application.h"

#include "MenuScene.h"
#include "ShapeObject.h"
#include "SpriteObject.h"

int main()
{
	MenuScene* main_game_scene = new MenuScene();
	main_game_scene->initialize();

	Application::getInstance()->setGameScene(main_game_scene);
	Application::getInstance()->createWindow(500, 500, std::string("Space Invaders New Age"));
	Application::getInstance()->start();
	return 0;
}