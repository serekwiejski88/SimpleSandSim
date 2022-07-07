#include "Game.h"
#include <iostream>

// Konstruktory, destruktory

Game::Game() {
	window = nullptr;
	initializeWindow();
}

Game::~Game() {
	delete this->window;
}

// Gettery i settery

const bool Game::getWindowIsOpen() const {
	return this->window->isOpen();
}

// Fukncje publiczne

void Game::update() {
	pollEvents();
	updateMousePos();
	updateObjects();
	window->clear(sf::Color(0, 0, 0, 255));
	mapka.update(window);
}

void Game::render() {
	window->clear(sf::Color(0, 0, 0, 255));
	mapka.render(window);
	window->display();
}

// Funkcje prywatne

void Game::initializeWindow() {
	videoMode.height = 500;
	videoMode.width = 500;
	window = new sf::RenderWindow(
		videoMode, "SandSim", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);
}

void Game::pollEvents() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void Game::updateMousePos() {
	mousePos = sf::Mouse::getPosition(*this->window);
}

void Game::updateObjects() {
	if (mousePos.x < window->getSize().x && mousePos.y < window->getSize().y) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mapka.clickedSandParticle(mousePos);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			mapka.clickedWaterParticle(mousePos);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {

		}
	}
}

