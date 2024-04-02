#include "CONSTANTS.h"


int menu() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "Space Invaders New Age", Style::None);

	//////////////////////////////////////////
	//////  MOUSE CURSOR INFO
	/////////////////////////////////////////

	Vector2i mousePosition;

	

	window.setMouseCursorVisible(false);	/////  HIDE CURSOR

	Font mainFont;
	mainFont.loadFromFile("resources/mainfont.otf");  // Main font

	Text title;
	title.setFont(mainFont);
	title.setString("Space Invaders: New Age");		// Main title "Space Invaders: New Age"
	title.setCharacterSize(30);
	title.setPosition(30, 250);

	Text settings;
	settings.setFont(mainFont);
	settings.setString("Settings");		// Main title "Space Invaders: New Age"
	settings.setCharacterSize(24);
	settings.setPosition(190, 250);

	//BACKGROUND DEFINITION game()

	BACKGROUND background;

	background.texture.loadFromFile("resources/backgrounds/background_start.jpg");
	background.sprite.setTexture(background.texture);

	Text sign_startgame;
	sign_startgame.setFont(mainFont);
	sign_startgame.setString("Start Game");		// Main title "Start Game"
	sign_startgame.setCharacterSize(24);
	sign_startgame.setPosition(170, 200);

	Text exit;
	exit.setFont(mainFont);
	exit.setString("Exit");		// Main title "Exit"
	exit.setCharacterSize(24);
	exit.setPosition(225, 300);

	bool sign_startgame_hovered = false;

	Texture cursor_txt;
	cursor_txt.loadFromFile("resources/cursor.png");					//Game cursor

	Sprite cursor;
	cursor.setTexture(cursor_txt);

	//UFO DEFINITION menu()

	UFO ufo;
	ufo.texture.loadFromFile("resources/sprites/ufo_black.png");
	ufo.sprite.setTexture(ufo.texture);
	ufo.sprite.setPosition(200, 350);
	ufo.to_left = true;



	bool titleUpAlready = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//COORDINATES DEFINITIONS menu()

		//Ufo coordinates definition menu()

		ufo.x = ufo.sprite.getPosition().x;
		ufo.y = ufo.sprite.getPosition().y;

		if (title.getPosition().y > 50) {
			title.move(0, -1);												//Title mobing up
																			/*Sleep(10);*/
			if (title.getPosition().y <= 50) {
				titleUpAlready = true;
			}
		}





		if (titleUpAlready == true) {

			if (ufo.to_left) {
				ufo.sprite.move(-1, 0);
				if (ufo.x == 100) {				//UFO animation left
					ufo.to_left = false;
				}
			}

			if (!ufo.to_left) {
				ufo.sprite.move(1, 0);
				if (ufo.x == 300) {				//UFO animation left
					ufo.to_left = true;
				}
			}


		}


		if (background.sprite.getPosition().y > -965) {
			background.sprite.move(0, -0.5);
		}
		else {														//Background animation
			background.sprite.setPosition(0, 0);
		}

		mousePosition = Mouse::getPosition(window);

		cursor.setPosition(float(mousePosition.x), float(mousePosition.y));


		// CHECHING MOUSE POSITION AND CLICKING ON MENU ITEM

		//Start Game

		if (mousePosition.x > 180 && mousePosition.x < 320 && mousePosition.y > 200 && mousePosition.y < 220) {

			sign_startgame.setCharacterSize(25);

			if (Mouse::isButtonPressed(Mouse::Left)) {
				return 2;
			};

		}
		else {
			sign_startgame.setCharacterSize(24);
		}

		//Settings

		if (mousePosition.x > 190 && mousePosition.x < 310 && mousePosition.y > 250 && mousePosition.y < 275) {

			settings.setCharacterSize(25);

			if (Mouse::isButtonPressed(Mouse::Left)) {
				window.close();
				return 3;
			};

		}
		else {
			settings.setCharacterSize(24);
		}

		//Exit

		if (mousePosition.x > 220 && mousePosition.x < 280 && mousePosition.y > 300 && mousePosition.y < 330) {

			exit.setCharacterSize(25);

			if (Mouse::isButtonPressed(Mouse::Left)) {
				return 4;
			};

		}
		else {
			exit.setCharacterSize(24);
		}



		///////////////////////////////////////////////////////////////////////
		///////		DO NOT CREATE ANYTHING DOWN	
		///////////////////////////////////////////////////////////////////////

		window.clear();
		window.draw(background.sprite);
		window.draw(ufo.sprite);
		window.draw(title);

		if (titleUpAlready) {
			window.draw(sign_startgame);
		}

		window.draw(settings);
		window.draw(exit);
		window.draw(cursor);
		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			return 0;
		}

	}
}

