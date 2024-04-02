#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <SFML\Graphics.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace sf;
using namespace std;

struct CURSOR {
	Texture texture;
	Sprite sprite;
	float x;
	float y;
};

struct BACKGROUND {
	Texture texture;
	Sprite sprite;
};

struct IMAGE {
	Texture texture;
	Sprite sprite;
	float x;
	float y;
};

struct INDICATOR {
	Texture texture;
	Sprite sprite;
};

struct RIGHTUP
{
	Texture texture;
	Sprite sprite;
};

struct UFO
{
	Texture texture;
	Sprite sprite;
	bool to_left;
	bool failed;
	float x;
	float y;
	int HP;
	float speed;
	float left;
	int amount;
	bool spawned;
};

struct BULLET
{
	Texture texture;
	Sprite sprite;
	Music sound;
	float speed;
	float x;
	float y;
	int amount;
	int currentam;
	bool shooted;
	bool spawned;
};

struct PLANE
{
	Texture texture;
	Sprite sprite;
	float speed;
	float x;
	float y;
};

struct TEXT
{
	Font font;
	Text text;
};




int menu();
int settin();
int game();
int end();
#endif;

