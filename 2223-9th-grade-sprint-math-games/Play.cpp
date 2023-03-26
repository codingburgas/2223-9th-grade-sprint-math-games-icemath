#include "Play.h"

Play::Play(float weight, float height)
{
	if (!font.loadFromFile("../Fonts/UGOCOLOR.ttf"))
	{
		cout << "No font is here";
	}

	TasksNumber[0].setFont(font);
	TasksNumber[0].setFillColor(Color::White);
	TasksNumber[0].setString("TASK ");
	TasksNumber[0].setCharacterSize(70);
	TasksNumber[0].setPosition(150, 200);

	TasksNumber[1].setFont(font);
	TasksNumber[1].setFillColor(Color::White);
	TasksNumber[1].setString("Task 2");
	TasksNumber[1].setCharacterSize(70);
	TasksNumber[1].setPosition(150, 300);

	TasksNumber[2].setFont(font);
	TasksNumber[2].setFillColor(Color::White);
	TasksNumber[2].setString("Task 3");
	TasksNumber[2].setCharacterSize(70);
	TasksNumber[2].setPosition(150, 400);

	TasksNumber[3].setFont(font);
	TasksNumber[3].setFillColor(Color::White);
	TasksNumber[3].setString("Task 4");
	TasksNumber[3].setCharacterSize(70);
	TasksNumber[3].setPosition(350, 200);

	TasksNumber[4].setFont(font);
	TasksNumber[4].setFillColor(Color::White);
	TasksNumber[4].setString("Task 4");
	TasksNumber[4].setCharacterSize(70);
	TasksNumber[4].setPosition(350, 300);

	TasksNumber[5].setFont(font);
	TasksNumber[5].setFillColor(Color::White);
	TasksNumber[5].setString("Task 4");
	TasksNumber[5].setCharacterSize(70);
	TasksNumber[5].setPosition(350, 400);

	TasksNumber[6].setFont(font);
	TasksNumber[6].setFillColor(Color::White);
	TasksNumber[6].setString("Task 4");
	TasksNumber[6].setCharacterSize(70);
	TasksNumber[6].setPosition(550, 200);

	TasksNumber[7].setFont(font);
	TasksNumber[7].setFillColor(Color::White);
	TasksNumber[7].setString("Task 4");
	TasksNumber[7].setCharacterSize(70);
	TasksNumber[7].setPosition(550, 300);

	TasksNumber[8].setFont(font);
	TasksNumber[8].setFillColor(Color::White);
	TasksNumber[8].setString("Task 4");
	TasksNumber[8].setCharacterSize(70);
	TasksNumber[8].setPosition(550, 400);

	SelectedTasks = -1;

}

Play::~Play()
{

}

//Draw Tasks
void Play::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_tasks_number; ++i)
	{
		window.draw(TasksNumber[i]);
	}
}


//Move up
void Play::MoveUp()
{
	if (SelectedTasks - 1 >= 0)
	{
		TasksNumber[SelectedTasks].setFillColor(Color::White);

		SelectedTasks--;
		if (SelectedTasks == -1)
		{
			SelectedTasks = 2;
		}
		TasksNumber[SelectedTasks].setFillColor(Color::Blue);
	}
}

//Move down
void Play::MoveDown()
{
	if (SelectedTasks + 1 <= Max_tasks_number)
	{
		TasksNumber[SelectedTasks].setFillColor(Color::White);

		SelectedTasks++;
		if (SelectedTasks == 9)
		{
			SelectedTasks = 0;
		}
		TasksNumber[SelectedTasks].setFillColor(Color::Blue);
	}
}



void PLay()
{
    RenderWindow PLAY(VideoMode(960, 720), "Tasks", Style::Default);
	Play play(PLAY.getSize().x, PLAY.getSize().y);

	while (PLAY.isOpen())
	{
		Event event;
		while (PLAY.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				PLAY.close();
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					play.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					play.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					RenderWindow Task1(VideoMode(960, 720), "Task 1");
					RenderWindow Task2(VideoMode(960, 720), "Task 2");
					RenderWindow Task3(VideoMode(960, 720), "Task 3");
					RenderWindow Task4(VideoMode(960, 720), "Task 4");
					RenderWindow Task5(VideoMode(960, 720), "Task 5");
					RenderWindow Task6(VideoMode(960, 720), "Task 6");
					RenderWindow Task7(VideoMode(960, 720), "Task 7");
					RenderWindow Task8(VideoMode(960, 720), "Task 8");
					RenderWindow Task9(VideoMode(960, 720), "Task 9");

					int y = play.SelectedTasksPressed();
					if (y == 0)
					{
						while (Task1.isOpen())
						{
							Event aevent;
							while (Task1.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Task1.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Task1.close();
									}
								}
							}
							Task2.close();
							Task3.close();
							Task4.close();
							Task5.close();
							Task6.close();
							Task7.close();
							Task8.close();
							Task9.close();
							Task1.clear();
							Task1.display();
						}
					}
					if (y == 1)
					{
						while (Task2.isOpen())
						{
							Event aevent;
							while (Task2.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Task2.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Task2.close();
									}
								}
							}
							Task1.close();
							Task3.close();
							Task4.close();
							Task5.close();
							Task6.close();
							Task7.close();
							Task8.close();
							Task9.close();
							Task2.clear();
							Task2.display();
						}
					}
					if (y == 2)
					{
						while (Task3.isOpen())
						{
							Event aevent;
							while (Task3.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Task3.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Task3.close();
									}
								}
							}
							Task1.close();
							Task2.close();
							Task4.close();
							Task5.close();
							Task6.close();
							Task7.close();
							Task8.close();
							Task9.close();
							Task3.clear();
							Task3.display();
						}
					}
					if (y == 3)
					{
						while (Task4.isOpen())
						{
							Event aevent;
							while (Task4.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Task4.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Task4.close();
									}
								}
							}
							Task1.close();
							Task2.close();
							Task3.close();
							Task5.close();
							Task6.close();
							Task7.close();
							Task8.close();
							Task9.close();
							Task4.clear();
							Task4.display();
						}
					}
					if (y == 4)
					{
						while (Task5.isOpen())
						{
							Event aevent;
							while (Task5.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Task5.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Task5.close();
									}
								}
							}
							Task1.close();
							Task2.close();
							Task3.close();
							Task4.close();
							Task6.close();
							Task7.close();
							Task8.close();
							Task9.close();
							Task5.clear();
							Task5.display();
						}
					}
					if (y == 5)
					{
						while (Task6.isOpen())
						{
							Event aevent;
							while (Task6.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Task6.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Task6.close();
									}
								}
							}
							Task1.close();
							Task2.close();
							Task3.close();
							Task4.close();
							Task5.close();
							Task7.close();
							Task8.close();
							Task9.close();
							Task6.clear();
							Task6.display();
						}
					}
					if (y == 6)
					{
						while (Task7.isOpen())
						{
							Event aevent;
							while (Task7.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Task7.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Task7.close();
									}
								}
							}
							Task1.close();
							Task2.close();
							Task3.close();
							Task4.close();
							Task5.close();
							Task6.close();
							Task8.close();
							Task9.close();
							Task7.clear();
							Task7.display();
						}
					}
					if (y == 7)
					{
						while (Task8.isOpen())
						{
							Event aevent;
							while (Task8.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Task8.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Task8.close();
									}
								}
							}
							Task1.close();
							Task2.close();
							Task3.close();
							Task4.close();
							Task5.close();
							Task6.close();
							Task7.close();
							Task9.close();
							Task8.clear();
							Task8.display();
						}
					}
					if (y == 8)
					{
						while (Task9.isOpen())
						{
							Event aevent;
							while (Task9.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Task9.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Task9.close();
									}
								}
							}
							Task1.close();
							Task2.close();
							Task3.close();
							Task4.close();
							Task5.close();
							Task6.close();
							Task7.close();
							Task8.close();
							Task9.clear();
							Task9.display();
						}
					}
				}
			}
		}
		PLAY.clear();
		play.draw(PLAY);
		PLAY.display();
	}
}



