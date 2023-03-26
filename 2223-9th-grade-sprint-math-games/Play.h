#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class field {
private:
	struct QNA {
		string question;
		string answer;
	};

	vector<QNA> QNAV;

	sf::Text question;
	sf::Sprite background;
	sf::Font font;

public:
	sf::Text input;

	field(sf::Color bgColor, int sizeX, int sizeY, float posX, float posY, float scaleX, float scaleY, sf::Texture& backgroundTexture);

	void draw(sf::RenderWindow& window);

	void setQuestion(int row);

	bool checkAnswer(int row);
	
	
};