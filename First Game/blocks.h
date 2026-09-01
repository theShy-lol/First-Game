#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <vector>



class Lines {
public:
	Lines(int l, int nr);
	void breakL();
	void drawblock(sf::RenderWindow &w);
	std::vector<sf::RectangleShape>& getblocks();
private:
	int lives;
	sf::RectangleShape line;
	std::vector<sf::RectangleShape> blocks;
};
Lines::Lines(int l, int nr) {
	this->lives = l;
	float grid = 800.f;
	float spaceB = 200.f;
	float currentX = 0.f;
	float currentY = 0.f;
	while (nr > 0) {
		sf::RectangleShape gg;
		gg.setSize(sf::Vector2f(190.f, 50.f));
		gg.setOutlineThickness(7.f);
		gg.setOutlineColor(sf::Color::Black);
		gg.setFillColor(sf::Color::Cyan);
		gg.setPosition(sf::Vector2f(currentX, currentY));

		this->blocks.push_back(gg);
		currentX += spaceB;

		if (currentX >= grid){
			currentX = 0.5;
			currentY += 50.f;
		}
		nr--;
	}
}
void Lines::breakL() {
	if (this->lives <= 0) {
		this->line.setSize(sf::Vector2f(0.f, 0.f));
		
	}
}
void Lines::drawblock(sf::RenderWindow &w) {
	for (const auto& block : this->blocks) {
		w.draw(block);
	}
	
}
std::vector<sf::RectangleShape>& Lines::getblocks() {
	return this->blocks;
}
