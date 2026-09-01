#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>


class ball {
public:
	ball(float v, float g, sf::Vector2f s);
	void drawb(sf::RenderWindow& w);
	void update(float dt);
	bool collidesWith(sf::RectangleShape& other);
	void richoshe(const sf::RectangleShape& p, std::vector<sf::RectangleShape>& b);
private:
	sf::Vector2f speed;
	sf::Vector2f direction;
	sf::CircleShape b;
	float velocity;
	float gravity;
	
};
ball::ball(float v, float g, sf::Vector2f s) {
	this->b.setPosition(sf::Vector2f(350, 300));
	this->b.setRadius(15.f);
	this->b.setFillColor(sf::Color(255, 255, 255));
	this->velocity = v;
	this->gravity = g;
	this->speed = s;
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

void ball::richoshe(const sf::RectangleShape& p, std::vector<sf::RectangleShape>& b) {
	sf::FloatRect ballBound = this->b.getGlobalBounds();
	sf::FloatRect playerBound = p.getGlobalBounds();
	if (ballBound.intersects(playerBound)) {
		this->speed.y = -std::abs(this->speed.y);
		std::cout << "Hit player"<<std::endl;
	}
	for (auto i = b.begin(); i != b.end();) {
		sf::FloatRect blockbounds = i->getGlobalBounds();
		if (ballBound.intersects(blockbounds)) {
			this->speed.y = std::abs(this->speed.y); 
			std::cout << "Block hit" << std::endl;
			i = b.erase(i);
			break;
		}
		else {
			
			++i;
		}
	}
	if (ballBound.left <= 0.0f) {
		this->speed.x *= -1.f;
		this->b.setPosition(10.0f, this->b.getPosition().y);
	}
	if (ballBound.left + ballBound.width >= 800.0f) {
		this->speed.x = -std::abs(this->speed.x);
	}
}
void ball::update(float dt) {
	this->b.move(this->speed);
}
