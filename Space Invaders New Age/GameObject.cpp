#include "GameObject.h"

void GameObject::addChild(GameObject* in_game_object)
{
	_children.push_front(in_game_object);
}

void GameObject::render()
{
	for (const auto& child : getChildren())
	{
		child->render();
	}
}

