#include "defaultMenu.h"
#include "About.h"
void defaultMenu()
{
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
	aboutTexture.loadFromFile("../photos/backgroundAbout.jpg");
	aboutBackground.setTexture(&aboutTexture);

	//set background for play
	RectangleShape playBackground;
	playBackground.setSize(Vector2f(960, 720));
	Texture Playtexture;
	Playtexture.loadFromFile("../photos/background.png");
	playBackground.setTexture(&Playtexture);


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
					RenderWindow OPTIONS(VideoMode(960, 720), "OPTIONS");
					RenderWindow ABOUT(VideoMode(960, 720), "ABOUT");

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (Play.isOpen())
						{
							Event aevent;
							while (Play.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Play.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Play.close();
									}
								}
							}
							OPTIONS.close();
							ABOUT.close();
							Play.clear();
							Play.draw(playBackground);
							Play.display();
						}
					}
					if (x == 1)
					{
						while (OPTIONS.isOpen())
						{
							Event aevent;
							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									OPTIONS.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										OPTIONS.close();
									}
								}
							}
							Play.close();
							OPTIONS.clear();
							ABOUT.close();
							OPTIONS.display();
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
							OPTIONS.close();
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