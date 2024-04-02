#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <deque>

class Application
{
private:
	static Application* _app_instance;
	sf::RenderWindow* _app_window { nullptr };
	class GameScene* _game_scene { nullptr };

	std::deque<sf::Drawable*> _render_queue;
	void renderQueue();

public:
	static Application* getInstance();

	void createWindow(sf::VideoMode& in_video_mode, std::string& in_window_title);
	void setGameScene(GameScene* in_game_scene) { _game_scene = in_game_scene; }
	void start();
	void render(sf::Drawable* in_drawable);
};