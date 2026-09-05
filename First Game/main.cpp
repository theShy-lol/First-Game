#include <SFML/Graphics.hpp>
#include <iostream>
#include "blocks.h"
#include "ball.h"
int main()
{	
	//Shader + Clock
	sf::Clock clock;
	sf::Clock globalClock;
	sf::Shader shader;
	if (!shader.loadFromFile("vertex.vert", "shader.frag")) {
		std::cout << "Couldn't load shader!" << std::endl;
	}
	//Start
	float dt = 0;
	sf::Vector2f speed(250.0f,250.0f);
	sf::RenderWindow window(sf::VideoMode({800, 600}), "Playball");
	sf::Shader bgShader;
	bgShader.loadFromFile("background.frag", sf::Shader::Fragment);
	bgShader.setUniform("uResolution", sf::Vector2f(800.f, 600.f));
	sf::RectangleShape bgShape(sf::Vector2f(800.f, 600.f));
	sf::RectangleShape p1(sf::Vector2f(200.f, 20.f));
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	//Entities
	sf::Texture dummy;
	p1.setFillColor(sf::Color(255, 255, 255));
	dummy.create(1, 1);
	p1.setTexture(&dummy);
	p1.setPosition(300.f, 575.f);
	Lines blocks(12);
	ball ball1(speed, 0);
	//Font
	sf::Font font;
	if (!font.loadFromFile("Fonts/1.ttf")) {
		std::cout << "Couldn't open font" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(sf::Vector2f(20.f, 15.f));
	


	while (window.isOpen()) {
		sf::Event event;
		dt = clock.restart().asSeconds();
		float tt = globalClock.getElapsedTime().asSeconds();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || ball1.getPosition().top >= 600 ) {
				std::cout << "Game Over!" << std::endl;
				window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			p1.move(-360 * dt, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			p1.move(360 * dt, 0.f);
		}
		if (p1.getPosition().x  <  0)  {
			p1.setPosition(0.f, p1.getPosition().y);
		}
		if (p1.getPosition().x > 600) {
			p1.setPosition(600.f, p1.getPosition().y);
		}
		bgShader.setUniform("uTime", tt);
		shader.setUniform("uTime", tt);
		ball1.update(dt);
		window.clear(sf::Color::Black);
		ball1.richoshe(p1, blocks.getblocks());
		window.draw(bgShape, &bgShader);
		window.draw(p1);
		window.draw(p1, &shader);
		blocks.drawblock(window);
		ball1.drawb(window);
		window.draw(text);
		text.setString("Score: " + std::to_string(ball1.getScore()));
		window.display();
	}
}