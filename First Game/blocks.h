#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>



class Lines {
public:
	Lines(int l);
	void breakL();
	void drawblock(sf::RenderWindow &w, int nr);
private:
	int lives;
	sf::RectangleShape line;
};
Lines::Lines(const int l) {
	this->lives = l;
	this->line.setSize(sf::Vector2f(200.f, 50.f));
	this->line.setOutlineThickness(7.f);
	this->line.setOutlineColor(sf::Color::Black);
	this->line.setFillColor(sf::Color::Cyan);
}
void Lines::breakL() {
	if (this->lives <= 0) {
		this->line.setSize(sf::Vector2f(0.f, 0.f));
		
	}
}
void Lines::drawblock(sf::RenderWindow &w, int nr) {
	float grid = 800.f;
	float spaceB = 200.f;
	sf::RectangleShape gg;
	gg = this->line;
	while (nr > 0) {
		w.draw(gg);
		gg.move(sf::Vector2f(spaceB, 0.f));
		
		if (gg.getPosition().x >= grid) {
			gg.setPosition(0.f, gg.getPosition().y + 50);
		}
		
		nr--;
	}
	
}
