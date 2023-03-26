#include "defaultMenu.h"
#include "About.h"
#include "Play.h"


void scoreDisplay(RenderWindow& window, int score, RectangleShape& playBackground)
{
	Font font;
	font.loadFromFile("../Fonts/UGOCOLOR.ttf");
	Text text;
	text.setString("YOUR SCORE IS: " + to_string(score));
	text.setCharacterSize(36);
	text.setPosition(250, 350);
	text.setFont(font);
	Event ev;
	while (window.isOpen())
	{
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::KeyPressed)
			{
				if (ev.key.code == sf::Keyboard::Escape)
				{
					window.close();
					return;
				}
			}
		}
		window.clear();
		window.draw(playBackground);
		window.draw(text);
		window.display();
	}
}


void defaultMenu()
{
	int score = 0;
	int questionCounter = 0;
	

	RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	//set  background
	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	Texture Maintexture;
	Maintexture.loadFromFile("../photos/background.png");
	background.setTexture(&Maintexture);

	//about
	RectangleShape aboutBackground;
	aboutBackground.setSize(Vector2f(960, 720));
	Texture aboutTexture;
	aboutTexture.loadFromFile("../photos/backgroundAbout.png"); 
	aboutBackground.setTexture(&aboutTexture);

	//set background for play
	RectangleShape playBackground;
	playBackground.setSize(Vector2f(960, 720));
	Texture Playtexture;
	Playtexture.loadFromFile("../photos/Background-ICEMATH-1.png");
	playBackground.setTexture(&Playtexture);

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("../photos/Background-ICEMATH-1.png");
	field play(Color::White, 0, 0, 0, 0, 1.0670, 1.0670, backgroundTexture);

	/*RectangleShape lesson1;
	lesson1.setSize(Vector2f(960, 720));
	Texture lessons1texture;
	lessons1texture.loadFromFile("../photos/ANDoperator.png");
	lesson1.setTexture(&lessons1texture);
	lesson1.setScale(Vector2f(1.0615, 1.0611));*/

	string answer;
	int row = 0;
	int lessonsCounter = 0;

	Texture picture1;
	Sprite pictureSprite1;
	picture1.loadFromFile("../photos/Bitwise_AND-1.png");
	pictureSprite1.setTexture(picture1);
	pictureSprite1.setScale(1.0615, 1.0611);

	Texture picture2;
	Sprite pictureSprite2;
	picture2.loadFromFile("../photos/Bitwise_OR-1.png");
	pictureSprite2.setTexture(picture2);
	pictureSprite2.setScale(1.0615, 1.0611);

	Texture picture3;
	Sprite pictureSprite3;
	picture3.loadFromFile("../photos/Bitwise_XOR-1.png");
	pictureSprite3.setTexture(picture3);
	pictureSprite3.setScale(1.0615, 1.0611);

	Texture picture4;
	Sprite pictureSprite4;
	picture4.loadFromFile("../photos/Bitwise_-~.png");
	pictureSprite4.setTexture(picture4);
	pictureSprite4.setScale(1.0615, 1.0611);

	Texture picture5;
	Sprite pictureSprite5;
	picture5.loadFromFile("../photos/Right_shift-1.png");
	pictureSprite5.setTexture(picture5);
	pictureSprite5.setScale(1.0615, 1.0611);

	Texture picture6;
	Sprite pictureSprite6;
	picture6.loadFromFile("../photos/Left_shift-1.png");
	pictureSprite6.setTexture(picture6);
	pictureSprite6.setScale(0.36, 0.37);

	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MENU.close();
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					RenderWindow Play(VideoMode(960, 720), "Icemath");
					RenderWindow LESSONS(VideoMode(960, 720), "LESSONS");
					RenderWindow ABOUT(VideoMode(960, 720), "ABOUT");

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (Play.isOpen())
						{
							Event aevent;
							while (Play.pollEvent(event)) {
								// if any text is entered
								if (event.type == event.TextEntered) {

									// if enter is pressed
									if (event.text.unicode == 13) 
									{
										if (play.checkAnswer(row)) 
										{
											//if answer is correct
											score++;
										}
										row = rand() % 12;
										play.setQuestion(row);
										answer = "";
										questionCounter++;
										if (questionCounter > 12)
										{
											scoreDisplay(Play, score, playBackground);
										}
									} 

									// if backspace is pressed
									else if (event.text.unicode == 8) {
										if (!answer.empty()) {
											answer.pop_back();
										}
									}
									// if ([А-я] || [0-9] || space || minus) is pressed
									else if ((event.text.unicode >= 1040 && event.text.unicode <= 1117) || (event.text.unicode <= 57 && event.text.unicode >= 48) || event.text.unicode == 32 || event.text.unicode == 45) {
										// convert from upper to lower case
										if (event.text.unicode >= 1040 && event.text.unicode <= 1071) {
											answer += event.text.unicode + 32;
										}
										else {
											answer += event.text.unicode;
										}
									}
									play.input.setString(answer);
								}

								else if (event.type == sf::Event::Closed) {
									Play.close();
								}

							}
							LESSONS.close();
							ABOUT.close();
							Play.clear();
							play.draw(Play);
							Play.display();
						}
					}
					if (x == 1)
					{
						while (LESSONS.isOpen())
						{
							Event aevent;
							while (LESSONS.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									LESSONS.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									cout << event.key.code << endl;
									if (aevent.key.code == Keyboard::Escape)
									{
										LESSONS.close();
									}
									else if (event.key.code == 58) 
									{
										lessonsCounter++;
										if (lessonsCounter > 5) 
										{
											LESSONS.close();
										}
									}
									else if (event.key.code == 58)
									{
										lessonsCounter++;
										if (lessonsCounter > 5)
										{
											LESSONS.close();
										}
									}
								}
								
							}
							Play.close();
							LESSONS.clear();
							ABOUT.close();
							if (lessonsCounter == 0)
							{
								LESSONS.draw(pictureSprite1);
							}
							else if (lessonsCounter == 1)
							{
								LESSONS.draw(pictureSprite2);
							}
							else if (lessonsCounter == 2)
							{
								LESSONS.draw(pictureSprite3);
							}
							else if (lessonsCounter == 3)
							{
								LESSONS.draw(pictureSprite4);
							}
							else if (lessonsCounter == 4)
							{
								LESSONS.draw(pictureSprite5);
							}
							else if (lessonsCounter == 5)
							{
								LESSONS.draw(pictureSprite6);
							}
							LESSONS.display();
						}
					}
					if (x == 2)
					{
						while (ABOUT.isOpen())
						{
							Event aevent;
							while (ABOUT.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									ABOUT.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										ABOUT.close();
									}
								}
							}
							Play.close();
							LESSONS.close();
							ABOUT.clear();
							ABOUT.draw(aboutBackground);
							ABOUT.display();
						}
					}
					if (x == 3)
						MENU.close();
					break;
				}
			}
		}
		MENU.clear();
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}

}