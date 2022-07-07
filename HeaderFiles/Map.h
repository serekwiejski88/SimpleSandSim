#ifndef MAP_H
#define MAP_H

#include "Particlea.h"
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "sandParticle.h"
#include "voidParticle.h"
#include "waterParticle.h"
#include <iostream>
#include <unistd.h>
#include <vector>

class Map {
public:
	// Konstruktory i destruktory
	Map();
	virtual ~Map();

	// Funkcje publiczne
	void update(sf::RenderTarget *target);
	void render(sf::RenderTarget *target);
	void clickedSandParticle(sf::Vector2i mousePosition);
	void clickedWaterParticle(sf::Vector2i mousePosition);

  // Przeładowanie operatorów

	struct particleCount {
		int particlecount;

		particleCount() {
			particlecount = 0;
		}
	};

	struct incrementValue {
		int value;

		incrementValue() {
			value = 1;
		}
	};
  particleCount partcount;
	incrementValue incrementvalue;

protected:
private:
	// Zmienne prywatne
	void updateParticles();
	int mapHeight = 50 - 1;
	int mapWidth = 50 - 1;
	float cellSize = 10.f;
	sf::Vector2f cellVector;
	std::vector<std::vector<Particlea *>> mapVector;

	// Funkcje Prywatne
	std::vector<int> getSurroundings(int x, int y);
	void renderTileMap(sf::RenderTarget *target);
	void moveParticles(sf::RenderTarget *target);
	void switchPlaces(int x, int y, int xdiff, int ydiff);
};
#endif // MAP_H
