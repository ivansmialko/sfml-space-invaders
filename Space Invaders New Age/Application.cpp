#include <iostream>
#include <windows.h>
#include "Application.h"
#include "GameObject.h"
#include "GameScene.h"

Application* Application::_app_instance = nullptr;

Application* Application::getInstance()
{
	if (!_app_instance)
	{
		_app_instance = new Application();
	}

	return _app_instance;
}

void Application::createWindow(size_t in_width, size_t in_height, std::string& in_window_title)
{
	if (_app_window)
		return;

	_app_window = new sf::RenderWindow(sf::VideoMode(in_width, in_height), in_window_title, sf::Style::Default);
}

void Application::start()
{
	if(!_game_scene)
		return;

	while (_app_window->isOpen())
	{
		sf::Event event;
		while (_app_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_app_window->close();
		}
		_app_window->clear();

		_game_scene->update(getDelta());
		_game_scene->render();

		renderQueue();

		_app_window->display();
	}
}

void Application::render(sf::Drawable* in_drawable)
{
	_render_queue.push_front(in_drawable);
}

void Application::logText(std::string& in_text)
{
	OutputDebugStringA(in_text.c_str());
}

void Application::renderQueue()
{
	for (auto drawable : _render_queue)
	{
		_app_window->draw(*drawable);
	}
}

float Application::getDelta()
{
	static sf::Clock delta_clock;
	const float delta_time{ delta_clock.getElapsedTime().asSeconds() };
	delta_clock.restart();

	return delta_time;
}
