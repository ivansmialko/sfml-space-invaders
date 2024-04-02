#include "CONSTANTS.h"

void openFileG(fstream& file, string fileName, int fileMode) {

	file.open(fileName, fileMode);
	if (!file.is_open())
	{
		cout << "Can't open " << fileName << " Exiting..." << endl;
		system("pause");
		exit(1);
	}
}



int game() {

	RenderWindow window(sf::VideoMode(900, 650), "Space Invaders: New Age", Style::None);

	fstream game_controlling_type_g;

	openFileG(game_controlling_type_g, "data/data.sina", ios_base::in);
	bool game_controlling_type_writed = false;
	string controlling;
	game_controlling_type_g >> controlling;

	Vector2i mousePosition; //OBJECT FOR MOUSE COORDINATES
	window.setMouseCursorVisible(false);	/////  HIDE CURSOR

	Font mainFont; // Object for font
	mainFont.loadFromFile("resources/mainfont.otf");  // Main font


	//GAMEOVER TITLE
	Text ps;

	ps.setFont(mainFont);
	ps.setCharacterSize(30);
	ps.setPosition(430, 200);
	ps.setString("GAME OVER");

	Text gameover;

	gameover.setFont(mainFont);
	gameover.setCharacterSize(20);
	gameover.setPosition(460, 250);

	

	//BACKGROUND DEFINITION game()
	BACKGROUND background;

	background.texture.loadFromFile("resources/backgrounds/background_game.png");
	background.sprite.setTexture(background.texture);

	//CURSOR DEFINITION game()
	GameCursor cursor;

	cursor.texture.loadFromFile("resources/sprites/cursor_game.png");
	cursor.sprite.setTexture(cursor.texture);

	// PLANE DEFINITION game()
	Player plane;
	plane.texture.loadFromFile("resources/player_plane.png");
	plane.sprite.setTexture(plane.texture);
	plane.sprite.setPosition(450, 500);

	//UFO DEFINITION game()
	UFO ufo;
	ufo.texture.loadFromFile("resources/sprites/ufo_black.png");
	ufo.sprite.setTexture(ufo.texture);
	ufo.sprite.setPosition(50, 0);
	ufo.sprite.setOrigin(50, 50);
	ufo.failed = false;
	ufo.to_left = true;
	ufo.left = 100;
	Music ufo_sound;
	ufo_sound.openFromFile("resources/sounds/bang.ogg");
	const int ufo_am = 15;
	ufo.amount = ufo_am;
	ufo.speed = 0.05f;
	int ufo_x = 50;
	int ufo_y = 0;
	ufo.x = 0;
	ufo.y = 0;


	UFO ufo_arr[ufo_am];

	for (int i = 0; i < ufo.amount; i++) {
		ufo_arr[i] = ufo;
		if (i % 5 == 0) {
			ufo_y += 100;
			ufo_x = 50;
		}
		ufo_arr[i].sprite.move(float(ufo_x), float(ufo_y));
		ufo_x += 170;
	}

	//BOSS

	UFO boss;

	boss.texture.loadFromFile("resources/sprites/ufo_boss.png");
	boss.sprite.setTexture(boss.texture);
	boss.sprite.setPosition(300, 0);
	Music bosssound;
	bosssound.openFromFile("resources/sounds/bosssound.ogg");
	bosssound.setLoop(true);
	boss.spawned = false;
	boss.amount = 1;
	boss.HP = 100;


	// BUlLET DEFINITION game()
	Bullet bullet;
	bullet.texture.loadFromFile("resources/bullet.png");
	bullet.sprite.setTexture(bullet.texture);
	bullet.sprite.setScale(float(0.06), float(0.06));
	bullet.shooted = false;
	bullet.spawned = false;
	bullet.sound.openFromFile("resources/sounds/shoot.ogg");
	const int bullet_am = 5;
	bullet.amount = bullet_am;
	bullet.currentam = 0;
	bullet.speed = 1;
	bullet.sprite.setPosition(500, 500);

	Bullet bullet_arr[bullet_am];

	Bullet ufo_bullet;

	ufo_bullet.texture.loadFromFile("resources/sprites/ufo_bullet.png");
	ufo_bullet.sprite.setTexture(ufo_bullet.texture);
	ufo_bullet.shooted = false;
	ufo_bullet.spawned = false;
	ufo_bullet.sound.openFromFile("resources/sounds/shoot.ogg");
	const int ufo_bullet_am = 5;
	ufo_bullet.amount = bullet_am;
	ufo_bullet.currentam = 0;
	ufo_bullet.speed = 1;
	ufo_bullet.sprite.setPosition(500, 500);

	IMAGE background_end;
	background_end.texture.loadFromFile("resources/backgrounds/background_game_end.png");
	background_end.sprite.setTexture(background_end.texture);
	background_end.sprite.setPosition(1000, 1000);

	IMAGE meteor;

	meteor.texture.loadFromFile("resources/sprites/meteor.png");
	meteor.sprite.setTexture(meteor.texture);
	meteor.sprite.setScale(float(0.07), float(0.07));
	meteor.sprite.setOrigin(200, 200);
	meteor.texture.setSmooth(true);

	IMAGE meteor2;

	meteor2.texture.loadFromFile("resources/sprites/meteor.png");
	meteor2.sprite.setTexture(meteor.texture);
	meteor2.sprite.setScale(float(0.07), float(0.07));
	meteor2.sprite.setOrigin(200, 200);
	meteor2.texture.setSmooth(true);

	// INTERFACE DEFINITION game()

	IMAGE bottom_panel;

	bottom_panel.texture.loadFromFile("resources/sprites/interface/panel_bottom.png");
	bottom_panel.sprite.setTexture(bottom_panel.texture);
	bottom_panel.sprite.setPosition(0, 451);

	IMAGE top_left_panel;

	top_left_panel.texture.loadFromFile("resources/sprites/interface/top_left_panel.png");
	top_left_panel.sprite.setTexture(top_left_panel.texture);
	top_left_panel.sprite.setPosition(850, 0);

	RIGHTUP rightup;

	rightup.texture.loadFromFile("resources/sprites/interface_right_up.png");
	rightup.sprite.setTexture(rightup.texture);
	rightup.sprite.setPosition(700, 0);

	INDICATOR speedboost;

	speedboost.texture.loadFromFile("resources/sprites/indicators/speedboost.png");
	speedboost.sprite.setTexture(speedboost.texture);
	speedboost.sprite.setPosition(25, 50);

	INDICATOR speeddown;

	speeddown.texture.loadFromFile("resources/sprites/indicators/speeddown.png");
	speeddown.sprite.setTexture(speeddown.texture);
	speeddown.sprite.setPosition(25, 120);

	INDICATOR timeslow;

	timeslow.texture.loadFromFile("resources/sprites/indicators/timeslow.png");
	timeslow.sprite.setTexture(timeslow.texture);
	timeslow.sprite.setPosition(25, 190);

	//GAME DATA

	int score = 0;

	Text title;
	title.setFont(mainFont);
	title.setCharacterSize(22);
	title.setPosition(10, 607);

	int wave = 0;

	Text help;
	help.setFont(mainFont);
	help.setCharacterSize(20);
	help.setPosition(30, 0);

	int bossHP = 100;

	boss.failed = false;

	Text bosshp;
	bosshp.setFont(mainFont);
	bosshp.setCharacterSize(20);
	bosshp.setPosition(30, 0);

	Music boss_bang;
	boss_bang.openFromFile("resources/sounds/boss_bang.ogg");

	int totalscore = 0;

	//GAME LOOP DEFINITION

	int timer = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return 1;
		}

		window.clear();

		//COORDINATES DEFINITION BLOCK

		//Bullet coordinates definition game()
		bullet.x = bullet.sprite.getPosition().x;
		bullet.y = bullet.sprite.getPosition().y;

		//Enemy  bullet coordinates definition game()
		ufo_bullet.x = ufo_bullet.sprite.getPosition().x;
		ufo_bullet.y = ufo_bullet.sprite.getPosition().y;

		//Plane coordinates definition
		plane.x = plane.sprite.getPosition().x;
		plane.y = plane.sprite.getPosition().y;

		//Boss coordinates definition
		boss.x = boss.sprite.getPosition().x;
		boss.y = boss.sprite.getPosition().y;

		//Cursor coordinates definition
		mousePosition = Mouse::getPosition(window);
		cursor.x = float(mousePosition.x);
		cursor.y = float(mousePosition.y);
		cursor.sprite.setPosition(cursor.x - 10, cursor.y - 10);

		window.draw(background.sprite);
		window.draw(cursor.sprite);

		//Check meteor and move meteor

		if (meteor.sprite.getPosition().x > 900 || meteor.sprite.getPosition().y > 600) {
			meteor.sprite.setPosition(float(rand() % -100), float(rand() % 1000));
		}

		meteor.sprite.move(0.1f, 0.1f);
		meteor.sprite.rotate(0.5);

		if (meteor2.sprite.getPosition().x > 900 || meteor2.sprite.getPosition().y > 600) {
			meteor2.sprite.setPosition(float(rand() % 900), float(rand() % 600));
		}

		meteor2.sprite.move(0.1f, 0.1f);
		meteor2.sprite.rotate(0.5);

		window.draw(meteor.sprite);
		window.draw(meteor2.sprite);

		//Checking side

		if (ufo_arr[0].sprite.getPosition().x < 50 && ufo.to_left == true) {
			ufo.to_left = false;
			for (int i = 0; i < ufo.amount; i++) {
				ufo_arr[i].sprite.move(0, 1);
			}
		}

		if (ufo_arr[ufo.amount - 1].sprite.getPosition().x > 850) {
			ufo.to_left = true;
			for (int i = 0; i < ufo.amount; i++) {
				ufo_arr[i].sprite.move(0, 1);
			}
		}


		if (score < 15 && boss.spawned == false) {

			for (int i = 0; i < ufo.amount; i++) {

				//Ufo move

				if (ufo.to_left == true) {
					for (int i = 0; i < ufo.amount; i++) {
						ufo_arr[i].sprite.move(ufo.speed * -1, 0);
					}
				}
				else {
					for (int i = 0; i < ufo.amount; i++) {
						ufo_arr[i].sprite.move(ufo.speed, 0);
					}
				}

				if (ufo_arr[i].failed == false) {
					window.draw(ufo_arr[i].sprite);
				}

			}

			// Is rocket colised with ufo

			if(boss.spawned == false){
				for (int i = 0; i < ufo.amount; i++) {
					if (bullet.x > ufo_arr[i].sprite.getPosition().x - 50 && bullet.x < ufo_arr[i].sprite.getPosition().x + 100) {
						if (bullet.y > ufo_arr[i].sprite.getPosition().y && bullet.y < ufo_arr[i].sprite.getPosition().y + 20) {
							if (ufo_arr[i].failed == false && bullet.spawned == true) {
								ufo_arr[i].failed = true;
								bullet.spawned = false;
								score++;
								totalscore++;
								ufo_sound.play();
							}
						}
					}
				}
			}

		}
		else if (boss.spawned == false) {
			score = 0;
			wave++;
			for (int i = 0; i < ufo.amount; i++) {
				ufo_arr[i].failed = false;
			}
		}

		if (boss.spawned == true && boss.failed == false) {
			if (ufo_bullet.spawned == false) {
				ufo_bullet.shooted = true;
				ufo_bullet.sound.play();
			}
			if (ufo_bullet.shooted == true) {
				ufo_bullet.sprite.setPosition(boss.sprite.getPosition().x + 70, boss.sprite.getPosition().y + 220);
				ufo_bullet.spawned = true;
				ufo_bullet.shooted = false;
			}

			if (ufo_bullet.sprite.getPosition().y > 700) {
				ufo_bullet.spawned = false;
			}
			else {
				ufo_bullet.sprite.move(0, ufo_bullet.speed);
				window.draw(ufo_bullet.sprite);
			}
		}

		//Spawn BOSS

		if (wave > 0 && boss.amount == 1 && bullet.spawned == false) {
			window.draw(boss.sprite);
			ufo_bullet.spawned = false;
			bullet.spawned = false;
			boss.spawned = true;
			boss.amount = 0;
			
			
		}

		if (boss.spawned == true && boss.failed == false) {

			window.draw(boss.sprite);

			if (boss.sprite.getPosition().x < 50 && boss.to_left == true) {
				boss.to_left = false;
			}

			if (boss.sprite.getPosition().x > 600) {
				boss.to_left = true;
			}

			if (boss.to_left == true) {
				boss.sprite.move(-0.5, 0);
			}
			else {
				boss.sprite.move(0.5, 0);
			}
		}

		//Is player bullet collised with boss
		if (boss.spawned == true && boss.failed == false && bullet.spawned == true) {
		if (bullet.x > boss.x && bullet.x < boss.x + 300) {
			if (bullet.y > boss.y && bullet.y < boss.y + 300) {
				bullet.spawned = false;
				boss.HP -= rand()%5;	
				}
			}
		}

		//Is enemy bullet collised with player

		if (ufo_bullet.x > plane.x - 50 && ufo_bullet.x < plane.x + 100) {
			if (ufo_bullet.y > plane.y && ufo_bullet.y < plane.y + 20) {
				gameover.setString("..killed by alien's guns");
				if (boss.spawned == true) {
					gameover.setString("..killed in fight with boss");
				}
				break;
			}
		}

		//BOSS bullet

		int ufo_shoot;

		if (ufo_bullet.spawned == false && boss.spawned == false) {
			ufo_bullet.shooted = true;
			bullet.sound.play();
		}

		if (ufo_bullet.shooted == true) {
			ufo_shoot = rand() % 15;
			if (ufo_arr[ufo_shoot].failed == false) {
				ufo_bullet.sprite.setPosition(ufo_arr[ufo_shoot].sprite.getPosition().x, ufo_arr[ufo_shoot].sprite.getPosition().y);
			}
			window.draw(ufo_bullet.sprite);
			ufo_bullet.spawned = true;
			ufo_bullet.shooted = false;
		}

		if (ufo_bullet.sprite.getPosition().y > 700) {
			ufo_bullet.spawned = false;
		}
		else {
			ufo_bullet.sprite.move(0, ufo_bullet.speed);
			window.draw(ufo_bullet.sprite);
		}


		//Bullet shooting



		if (Keyboard::isKeyPressed(Keyboard::Space) && bullet.spawned == false || Mouse::isButtonPressed(Mouse::Left) && bullet.spawned == false) {
			bullet.shooted = true;
		}

		if (bullet.shooted == true && bullet.spawned == false) {
			bullet.sprite.setPosition(float(plane.x + 41.5), float(plane.y + 20));
			bullet.spawned = true;
			bullet.shooted = false;
			bullet.sound.play();
		}

		if (bullet.spawned == true) {
			if (bullet.y < -50) {
				bullet.spawned = false;
			}
			else {
				bullet.sprite.move(0, bullet.speed * -1);
				window.draw(bullet.sprite);
			}
		}

		//Plane control
		if (controlling == "game-controlling-type:1") {
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				plane.sprite.move(-1, 0);
			}

			else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				plane.sprite.move(1, 0);
			}
		}
		else if(controlling == "game-controlling-type:2"){
			plane.sprite.setPosition(cursor.x - 50, 500);
		}


		window.draw(plane.sprite);

		if (Keyboard::isKeyPressed(Keyboard::LControl)) {
			window.draw(timeslow.sprite);
			Sleep(10);
		}

		if (boss.spawned == true) {
			title.setString("BOSS: " + to_string(boss.HP));
		}
		else {
			title.setString("Enemies left: " + to_string(30 - totalscore));
		}

		if (boss.spawned == false) {
			if (ufo_arr[ufo.amount - 1].sprite.getPosition().y > 380) {
				title.setPosition(500, 300);
				gameover.setString("..too long");
				break;
				return 0;
			}
		}



		float helpint = 380 - ufo_arr[ufo.amount - 1].sprite.getPosition().y;

		help.setString("Enemy help just in " + to_string(helpint) + " km!!");

		window.draw(bottom_panel.sprite);
		window.draw(top_left_panel.sprite);
		window.draw(title);
		if (boss.spawned == false) {
			window.draw(help);
		}

		boss.spawned = true;

		if (boss.HP <= 0) {
			boss.failed = true;
		}
		if (boss.failed == true) {
			cout << "LOL";
			boss_bang.play();
			background.sprite.setPosition(0, 0);
			for (int i = 0; i < 10000; i++) {
				boss.sprite.move(10, 0);
				boss.sprite.move(0, 10);
				boss.sprite.move(-10, 0);
				boss.sprite.move(0, -10);
			}
			return 8373;
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			return 1;
		}

		window.display();

	}

	IMAGE plane_damaged;
	plane_damaged.texture.loadFromFile("resources/sprites/plane_damaged.png");
	plane_damaged.sprite.setTexture(plane_damaged.texture);
	plane_damaged.texture.setSmooth(true);
	plane_damaged.sprite.setPosition(50, 50);


	Text retry;
	retry.setFont(mainFont);
	retry.setCharacterSize(30);
	retry.setPosition(30, 550);
	retry.setString("Retry");


	Text mainmenu;
	mainmenu.setFont(mainFont);
	mainmenu.setCharacterSize(30);
	mainmenu.setPosition(30, 600);
	mainmenu.setString("Main Menu");

	ufo_sound.play();

	while (window.isOpen())
	{



		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		mousePosition = Mouse::getPosition(window);
		cursor.x = float(mousePosition.x);
		cursor.y = float(mousePosition.y);
		cursor.sprite.setPosition(cursor.x - 10, cursor.y - 10);

		plane_damaged.sprite.move(0.1f, 0.1f);
		plane_damaged.sprite.setOrigin(50, 50);
		plane_damaged.sprite.rotate(0.1f);


		retry.setCharacterSize(30);
		if (cursor.x > 30 && cursor.x < 130) {
			if (cursor.y > 550 && cursor.y < 580) {
				retry.setCharacterSize(32);
				if (Mouse::isButtonPressed(Mouse::Left) || Mouse::isButtonPressed(Mouse::Right)) {
					return 2;

				}

			}
		}

		mainmenu.setCharacterSize(30);
		if (cursor.x > 30 && cursor.x < 200) {
			if (cursor.y > 610 && cursor.y < 630) {
				mainmenu.setCharacterSize(32);
				if (Mouse::isButtonPressed(Mouse::Left) || Mouse::isButtonPressed(Mouse::Right)) {
					return 1;

				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			return 1;
		}


		window.clear();
		window.draw(background.sprite);
		window.draw(retry);
		window.draw(mainmenu);
		window.draw(plane_damaged.sprite);
		window.draw(ps);
		window.draw(gameover);
		window.draw(cursor.sprite);
		window.display();

	}
}