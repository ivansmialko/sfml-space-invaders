#include "CONSTANTS.h"

void openFileS(fstream& file, string fileName, int fileMode) {

	file.open(fileName, fileMode);
	if (!file.is_open())
	{
		cout << "Can't open " << fileName << " Exiting..." << endl;
		system("pause");
		exit(1);
	}
}

int settin() {

	RenderWindow window (sf::VideoMode(500, 500), "Space Invaders New Age", Style::None);

	fstream game_controlling_type;

	openFileS(game_controlling_type, "data/data.sina", ios_base::out);
	bool game_controlling_type_writed = false;

	Vector2i mousePosition;

	BACKGROUND background;

	background.texture.loadFromFile("resources/backgrounds/background_start.jpg");
	background.sprite.setTexture(background.texture);

	Font mainFont;
	mainFont.loadFromFile("resources/mainfont.otf");  // Main font

	Text title;
	title.setFont(mainFont);
	title.setString("Controls");		// Text "Controls"
	title.setCharacterSize(30);

	bool istitleup = false;

	IMAGE keyboardimg;

	keyboardimg.texture.loadFromFile("resources/sprites/interface/keyboard.png");
	keyboardimg.sprite.setTexture(keyboardimg.texture);
	keyboardimg.sprite.setPosition(100, 250);
	keyboardimg.sprite.setTextureRect(IntRect(0, 0, 100, 100));

	IMAGE mouseimg;

	mouseimg.texture.loadFromFile("resources/sprites/interface/mouse.png");
	mouseimg.sprite.setTexture(mouseimg.texture);
	mouseimg.sprite.setPosition(300, 250);
	mouseimg.sprite.setTextureRect(IntRect(0, 0, 100, 100));


	CURSOR cursor;

	cursor.texture.loadFromFile("resources/sprites/cursor_game.png");
	cursor.sprite.setTexture(cursor.texture);

	int timer = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//GET MOUSE POSITION
		mousePosition = Mouse::getPosition(window);
		cursor.x = float(mousePosition.x);
		cursor.y = float(mousePosition.y);
		cursor.sprite.setPosition(cursor.x - 10, cursor.y - 10);

		//KEYBOARD IMAGE COORDINATES
		keyboardimg.x = keyboardimg.sprite.getPosition().x;
		keyboardimg.y = keyboardimg.sprite.getPosition().y;

		//MOUSE IMAGE COORDINATES
		mouseimg.x = mouseimg.sprite.getPosition().x;
		mouseimg.y = mouseimg.sprite.getPosition().y;

		//IS KEYBOARDIMG OVERLAY WITH CURSOR?
		keyboardimg.sprite.setTextureRect(IntRect(100, 0, 100, 100));
		if (cursor.x > keyboardimg.x && cursor.x < keyboardimg.x + 100) {
			if (cursor.y > keyboardimg.y && cursor.y < keyboardimg.y + 100) {
				keyboardimg.sprite.setTextureRect(IntRect(0, 0, 100, 100));
				if (Mouse::isButtonPressed(Mouse::Left) && game_controlling_type_writed == false) {
					game_controlling_type << "game-controlling-type:1";
					game_controlling_type_writed = true;
				}
			}
		}

		//IS MOUSEIMG OVERLAY WITH CURSOR?
		mouseimg.sprite.setTextureRect(IntRect(100, 0, 100, 100));
		if (cursor.x > mouseimg.x && cursor.x < mouseimg.x + 100) {
			if (cursor.y > mouseimg.y && cursor.y < mouseimg.y + 100) {
				mouseimg.sprite.setTextureRect(IntRect(0, 0, 100, 100));
				if (Mouse::isButtonPressed(Mouse::Left) && game_controlling_type_writed == false) {
					game_controlling_type << "game-controlling-type:2";
					game_controlling_type_writed = true;
				}
			}
		}


			

		if (background.sprite.getPosition().y > -965) {
			background.sprite.move(0, -1);
		}
		else {														//Background animation
			background.sprite.setPosition(0, 0);
		}

		timer++;

		if (timer < 300) {
			title.setPosition(180, 150);
		}
		else if (title.getPosition().y > 50) {
			title.move(0, -0.5);
			cout << "Lol";
		}

		if (title.getPosition().y <= 50) {
			istitleup = true;
		}

		window.clear();
		window.draw(background.sprite);
		if (istitleup == true) {
			window.draw(keyboardimg.sprite);
			window.draw(mouseimg.sprite);
		}

		window.draw(title);
		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			game_controlling_type.close();
			return 1;
		}
	}

	
}
