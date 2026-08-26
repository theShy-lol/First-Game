#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>

class Player {
public:
	Player(sf::RectangleShape p);
	void move();
private:
	sf::RectangleShape player;
};
Player::Player(sf::RectangleShape p) {
	this->player = p;
	p.setSize(sf::Vector2f(100.f, 50.f));
}
void Player::move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->player.move(-1.f, 0.f);
	}
}

