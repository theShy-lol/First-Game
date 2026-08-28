#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>

class ball {
public:
	ball(float v, float g);
	void drawb(sf::RenderWindow& w);
	bool collidesWith(sf::RectangleShape& other);
	void richoshe();
private:
	sf::CircleShape b;
	float velocity;
	float gravity;
};
ball::ball(float v, float g) {
	this->b.setPosition(sf::Vector2f(400, 300));
	this->b.setRadius(15.f);
	this->b.setFillColor(sf::Color(255, 255, 255));
	this->velocity = v;
	this->gravity = g;
}
void ball::drawb(sf::RenderWindow& w) {
	w.draw(this->b);
}
bool ball::collidesWith(sf::RectangleShape& other) {
	if (this->b.getRadius() <= other.getPosition().x) {
		return true;
	}
	return false;
}
