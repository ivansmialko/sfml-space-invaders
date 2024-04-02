#pragma once
#include <forward_list>

class GameScene;

class GameObject
{
	using ChildrenList = std::forward_list<GameObject*>;

private:
	double _x { 0.0 };
	double _y { 0.0 };
	ChildrenList _children;

protected:
	GameScene* _game_scene { nullptr };

public:
	GameObject() {}
	GameObject(GameScene * in_game_scene) :
		_game_scene{ in_game_scene } {}
		
	double getX() { return _x; }
	double getY() { return _y; }
	ChildrenList& getChildren() { return _children; }

	virtual void setX(double in_x) { _x = in_x; }
	virtual void setY(double in_y) { _y = in_y; }
	void setGameScene(GameScene* in_game_scene) { _game_scene = in_game_scene; }

	void addChild(GameObject* in_game_object);
	virtual void render();
};