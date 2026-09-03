#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <vector>



class Block {
public:
	Block();
	Block(char l, sf::Vector2f Position);
	void takeHit();
	void drawB (sf::RenderWindow& r)const;
	sf::FloatRect getGlobalBounds() const;
	int getLives();
private:
	sf::RectangleShape block;
	int lives = 3;
};

Block::Block() {
	this->block.setSize(sf::Vector2f(190.f, 50.f));
	this->block.setOutlineThickness(7.f);
	this->block.setOutlineColor(sf::Color::Black);
	this->block.setFillColor(sf::Color::White);
}
Block::Block(char l,sf::Vector2f Position) {
	this->lives = l;
	this->block.setSize(sf::Vector2f(190.f, 50.f));
	this->block.setOutlineThickness(7.f);
	this->block.setOutlineColor(sf::Color::Black);
	this->block.setFillColor(sf::Color::Cyan);
	this->block.setPosition(Position);
}
void Block::takeHit() {
	this->lives -= 1;
	this->block.setFillColor(sf::Color::Blue);
	if (this->lives == 2) {
		this->block.setFillColor(sf::Color::Green);
	}
}
void Block::drawB(sf::RenderWindow &r) const{
	r.draw(this->block);
}
sf::FloatRect Block::getGlobalBounds() const {
	return this->block.getGlobalBounds();
}
int Block::getLives() {
	return this->lives;
}

class Lines {
public:
	Lines(int nr);
	void drawblock(sf::RenderWindow &w);
	std::vector<Block>& getblocks();
private:
	std::vector<Block> blocks;
};
Lines::Lines(int nr) {
	float grid = 800.f;
	float spaceB = 200.f;
	float currentX = 0.f;
	float currentY = 0.f;
	while (nr > 0) {

		this->blocks.emplace_back(3,sf::Vector2f(currentX, currentY));
		currentX += spaceB;

		if (currentX >= grid){
			currentX = 0.5;
			currentY += 50.f;
		}
		nr--;
	}
}

void Lines::drawblock(sf::RenderWindow &w) {
	for (const auto& block : blocks) {
		block.drawB(w);
	} 
	
}
std::vector<Block>& Lines::getblocks() {
	return this->blocks;
}
