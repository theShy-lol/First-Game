#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>



class ball {
public:
	ball(float v, float g, sf::Vector2f s, int sc);
	void drawb(sf::RenderWindow& w);
	void update(float dt);
	bool collidesWith(Block& other);
	void richoshe(const sf::RectangleShape& p, std::vector<Block>& b);
	sf::FloatRect getPosition();
	int getScore ();
private:
	sf::Vector2f speed;
	sf::Vector2f direction;
	sf::CircleShape b;
	float velocity;
	float gravity;
	int score;
};
ball::ball(float v, float g, sf::Vector2f s, int sc) {
	this->b.setPosition(sf::Vector2f(350, 300));
	this->b.setRadius(15.f);
	this->b.setFillColor(sf::Color(255, 255, 255));
	this->velocity = v;
	this->gravity = g;
	this->speed = s;
	this->score = sc;
}
void ball::drawb(sf::RenderWindow& w) {
	w.draw(this->b);
}
bool ball::collidesWith(Block& other) {
	sf::FloatRect ballBound = this->b.getGlobalBounds();
	sf::FloatRect otherBound = other.getGlobalBounds();
	if (ballBound.intersects(otherBound)) {
		return true;
	}
	return false;
}
void ball::richoshe(const sf::RectangleShape& p, std::vector<Block>& b) {
	sf::FloatRect ballBound = this->b.getGlobalBounds();
	sf::FloatRect playerBound = p.getGlobalBounds();
	if (ballBound.intersects(playerBound)) {
		this->speed.y = -std::abs(this->speed.y);
	}
	for (auto i = b.begin(); i != b.end();) {
		sf::FloatRect blockbounds = i->getGlobalBounds();
		if (ballBound.intersects(blockbounds)) {
			i->takeHit();
			this->speed.y = std::abs(this->speed.y);
			this->speed.y += 0.5;
			if (i->getLives() <= 0) {
				i = b.erase(i);
				this->score += 1;
			}
			else {
				++i;
			}
			break;
			}
			else {
			++i;
			}
			if (ballBound.left <= 0.0f) {
				this->speed.x *= -1.f;
				this->b.setPosition(15.f, this->b.getPosition().y);
			}
			if (ballBound.left + ballBound.width >= 800.0f) {
				this->speed.x = -std::abs(this->speed.x);
			}
			if (ballBound.top <= 0.0f) {
				this->speed.y = std::abs(this->speed.y);
				this->b.setPosition(this->b.getPosition().x, 10.0f);
			}
		}
	}
void ball::update(float dt) {
	this->b.move(this->speed);
}

sf::FloatRect ball::getPosition() {
	sf::FloatRect ball = this->b.getGlobalBounds();
	return ball;
}
int ball::getScore(){
	return this->score;
}