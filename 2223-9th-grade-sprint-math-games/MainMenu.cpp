#include "MainMenu.h"
#include "Play.h"

MainMenu::MainMenu(float width, float height)
{
	if (font.loadFromFile("../Fonts/UGOCOLOR.ttf"))
	{
		cout << "No font is here";
	}
	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("PLAY");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(350, 200);
	//Options
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("LESSONS");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(350, 300);
	//About
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("ABOUT US");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(350, 400);
	//Exit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("EXIT");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(350, 500);



	MainMenuSelected = -1;
}
MainMenu::~MainMenu()
{

}
// Draw Main Menu
void MainMenu::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; ++i)
	{
		window.draw(mainMenu[i]);
	}
}

//Move up
void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

//Move down
void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected++;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

void MainMenu::defaultMenu()
{
	cout << "npc";
	Texture backgroundTexture;
	RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
	backgroundTexture.loadFromFile("../photos/backgroundTexture.png");
	field play(Color::White, 0, 0, 350, 350, 1, 1, backgroundTexture);

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
									if (aevent.key.code == Keyboard::Escape)
									{
										LESSONS.close();
									}
								}
							}
							Play.close();
							LESSONS.clear();
							ABOUT.close();
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
		mainMenu.draw(MENU);
		MENU.display();
	}
}




