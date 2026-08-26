#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>

class Lines {
public:
	Lines(int l);
	void breakL();
private:
	int lives = 3;
	sf::RectangleShape line;
};
Lines::Lines(const int l) {
	this->lives = l;
}
void Lines::breakL() {
	if (this->lives <= 0) {

	}
}