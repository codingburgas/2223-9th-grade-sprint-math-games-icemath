#pragma once
#include "MainMenu.h"

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

#define Max_tasks_number 9

void PLay();

class Play
{
public:
	Play(float width, float height);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int SelectedTasksPressed()
	{
		return SelectedTasks;
	}
	~Play();
	


private:
	int SelectedTasks;
	Font font;
	Text TasksNumber[Max_tasks_number];
};



