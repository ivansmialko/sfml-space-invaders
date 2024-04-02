#include "CONSTANTS.h"

int end() {

	RenderWindow window(sf::VideoMode(900, 650), "Space Invaders: New Age", Style::None);

	IMAGE background;
	background.texture.loadFromFile("resources/sprites/game_end.jpg");
	background.sprite.setTexture(background.texture);

	Font mainFont; // Object for font
	mainFont.loadFromFile("resources/mainfont.otf");  // Main font

	Text welcomehome;
	welcomehome.setFont(mainFont);
	welcomehome.setPosition(50, 50);
	welcomehome.setString("Welcome home, pilot!");

	Text history;
	history.setFont(mainFont);
	history.setPosition(100, 120);
	history.setCharacterSize(25);
	history.setString("All world will remember you.. you are a hero!");

	Text infinity;
	infinity.setFont(mainFont);
	infinity.setPosition(20,620);
	infinity.setCharacterSize(15);
	infinity.setString("Infinity Studio(c). 2016");

	Text itstep;
	itstep.setFont(mainFont);
	itstep.setPosition(20, 600);
	itstep.setCharacterSize(15);
	itstep.setString("This version produced only as IT STEP course work");

	Text mainmenu;
	mainmenu.setFont(mainFont);
	mainmenu.setCharacterSize(30);
	mainmenu.setPosition(700, 600);
	mainmenu.setString("Main Menu");

	Vector2i mousePosition; //OBJECT FOR MOUSE COORDINATES
	window.setMouseCursorVisible(false);	/////  HIDE CURSOR

	GameCursor cursor;
	cursor.texture.loadFromFile("resources/sprites/cursor_game.png");
	cursor.sprite.setTexture(cursor.texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return 1;
		}

		

		//Cursor coordinates definition
		mousePosition = Mouse::getPosition(window);
		cursor.x = float(mousePosition.x);
		cursor.y = float(mousePosition.y);
		cursor.sprite.setPosition(cursor.x - 10, cursor.y - 10);

		mainmenu.setCharacterSize(30);
		if (cursor.x > mainmenu.getPosition().x && cursor.x < mainmenu.getPosition().x + 170) {
			if (cursor.y > mainmenu.getPosition().y && cursor.y < mainmenu.getPosition().y + 30) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					return 1;
				}
				mainmenu.setCharacterSize(31);
			}
		}
		


		cursor.sprite.setPosition(cursor.x, cursor.y);



		window.clear();
		window.draw(background.sprite);
		window.draw(welcomehome);
		window.draw(history);
		window.draw(mainmenu);
		window.draw(infinity);
		window.draw(itstep);
		window.draw(cursor.sprite);
		window.display();
	}

}