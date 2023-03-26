#include "Play.h"
#include <time.h>

field::field(sf::Color bgColor, int sizeX, int sizeY, float posX, float posY, float scaleX, float scaleY, sf::Texture& backgroundTexture)
{
	this->background.setTexture(backgroundTexture);
	this->background.setPosition(sf::Vector2f(posX, posY));
	this->background.setScale(scaleX, scaleY);
	this->question.setFont(font);
	this->question.setCharacterSize(26);
	this->question.setFillColor(sf::Color(255, 255, 255));
	this->question.setPosition(sf::Vector2f(200, 257));
	this->font.loadFromFile("../Fonts/UGOCOLOR.ttf");
	this->input.setFont(this->font);
	this->input.setCharacterSize(36);
	this->input.setFillColor(sf::Color(255, 255, 255));
	this->input.setPosition(480 + 20, 400);


	this->QNAV = {
		{"WHAT IS THE ANSWER OF 13 AND 8", "8"},
		{"WHAT IS THE ANSWER OF 21 OR 3", "23"},
		{"WHAT IS THE ANSWER OF 24 XOR 60", "36"},
		{"WHAT IS THE COMPLEMENT OF 68", "-69"},
		{"WHAT IS THE ANSWER OF 17 RIGHT SHIFTED BY 3", "2"},
		{"WHAT IS THE ANSWER OF 8 LEFT SHIFTED BY 2", "32"},
		{"WHAT IS THE ANSWER OF 3 AND 77", "1"},
		{"WHAT IS THE ANSWER OF 25 OR 34", "59"},
		{"WHAT IS THE ANSWER OF 22 XOR 61", "43"},
		{"WHAT IS THE COMPLEMENT OF ~35", "-36"},
		{"WHAT IS THE ANSWER OF 91 RIGHT SHIFTED BY 2", "22"},
		{"WHAT IS THE ANSWER OF 92  3", "736"},
		{"", ""}
	};
}

// draw input field to the screen
void field::draw(sf::RenderWindow& window) {
	window.draw(this->background);
	window.draw(this->question);
	window.draw(this->input);
}

// get a random question
// takes integer up to 15 as an argument
void field::setQuestion(int row) {
	
	this->question.setString(this->QNAV[row].question);
}

// check if answer is correct
bool field::checkAnswer(int row) {
	return this->input.getString() == this->QNAV[row].answer;
}