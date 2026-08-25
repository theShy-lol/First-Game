#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>
int main()
{
	sf::RenderWindow window(sf::VideoMode({800, 600}), "Playball");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::Yellow);
		window.display();
	}
}