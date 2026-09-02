#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>
#include "player.h"
#include "blocks.h"
#include "ball.h"
int main()
{	
	sf::Clock clock;
	float dt = 0;
	sf::Vector2f speed(3.0f,3.0f);
	sf::RenderWindow window(sf::VideoMode({800, 600}), "Playball");
	sf::RectangleShape p1(sf::Vector2f(200.f, 20.f));
	p1.setFillColor(sf::Color(255, 0, 0));
	p1.setPosition(300.f, 575.f);
	Lines blocks(12);
	ball ball1(0, -9.5 , speed);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		sf::Event event;
		dt = clock.restart().asSeconds();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			p1.move(-6.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			p1.move(6.f, 0.f);
		}
		if (p1.getPosition().x  <  0)  {
			p1.setPosition(0.f, p1.getPosition().y);
		}
		if (p1.getPosition().x > 600) {
			p1.setPosition(600.f, p1.getPosition().y);
		}
		ball1.update(dt);
		window.clear(sf::Color::Black);
		ball1.richoshe(p1, blocks.getblocks());
		window.draw(p1);
		blocks.drawblock(window);
		ball1.drawb(window);
		window.display();
	}
}