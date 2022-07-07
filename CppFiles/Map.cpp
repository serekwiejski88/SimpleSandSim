#include "Map.h"
#include <iostream>

// Konstruktory i destruktory


Map::Map() {
	mapVector.resize(mapWidth + 1);

	for (int x = 0; x <= mapWidth; x++) {
		for (int y = 0; y <= mapHeight; y++) {
			Particlea *part =
				new voidParticle(x * cellSize, y * cellSize, cellSize);
			mapVector[x].push_back(part);
		}
	}

}

Map::~Map() {
	// dtor
}


std::ostream& operator<<(std::ostream  &cout, Map::particleCount partCount){
  cout << "Particle count:" << partCount.particlecount << std::endl;
  return cout;
}

Map::particleCount operator+(Map::particleCount &partCount, Map::incrementValue &incrementvalue){
  partCount.particlecount = partCount.particlecount + incrementvalue.value;
  return partCount;
}



// Funkcje publiczne

void Map::update(sf::RenderTarget *target) {
	moveParticles(target);
}

void Map::render(sf::RenderTarget *target) {
  system("clear");
	renderTileMap(target);
  std::cout << partcount;
}


//  Funkcje clickedSandParticle() oraz clickedWaterParticle() tworza czasteczki.

void Map::clickedSandParticle(sf::Vector2i mousePosition) {
	Particlea *part = new sandParticle(
		mapVector[mousePosition.x / cellSize][mousePosition.y / cellSize]
			->getPositionx(),
		mapVector[mousePosition.x / cellSize][mousePosition.y / cellSize]
			->getPositiony(),
		cellSize);
  delete mapVector[mousePosition.x / cellSize][mousePosition.y / cellSize];
	mapVector[mousePosition.x / cellSize][mousePosition.y / cellSize] = part;
}
void Map::clickedWaterParticle(sf::Vector2i mousePosition) {
	Particlea *part = new waterParticle(
		mapVector[mousePosition.x / cellSize][mousePosition.y / cellSize]
			->getPositionx(),
		mapVector[mousePosition.x / cellSize][mousePosition.y / cellSize]
			->getPositiony(),
		cellSize);
  delete mapVector[mousePosition.x / cellSize][mousePosition.y / cellSize];
	mapVector[mousePosition.x / cellSize][mousePosition.y / cellSize] = part;
}

// Funkcje prywatne

/*
  Funkcja moveParticles() odpowiada za ruch czasteczek.
*/

void Map::moveParticles(sf::RenderTarget *target) {
	for (int x = mapWidth; x >= 0; x--) {
		for (int y = mapHeight; y >= 0; y--) {
			if (mapVector[x][y]->isOccupied()) {
				int movePlace = mapVector[x][y]->move(getSurroundings(x, y));

				if (movePlace == 7) {
					if (y < mapHeight && x <= mapWidth)
						switchPlaces(x, y, 0, 1);
				}
				if (movePlace == 6) {
					if (y < mapHeight && x > 0)
						switchPlaces(x, y, -1, 1);
				}
				if (movePlace == 8) {
					if (y < mapHeight && x <= mapWidth)
						switchPlaces(x, y, 1, 1);
				}
				if (movePlace == 4) {
					if (y <= mapHeight && x > 0)
						switchPlaces(x, y, -1, 0);
				}
				if (movePlace == 5) {
					if (y <= mapHeight && x <= mapWidth)
						switchPlaces(x, y, 1, 0);
				}
				if (movePlace == 2) {
					if (y > 0)
						switchPlaces(x, y, 0, -1);
				}
			}
		}
	}
}

/*

Funkcja renderTileMap() wyswietla plansze na ekranie

*/
void Map::renderTileMap(sf::RenderTarget *target) {
 partcount.particlecount = 0;
	for (int x = 0; x <= mapWidth; x++) {
		for (int y = 0; y <= mapHeight; y++) {
			mapVector[x][y]->render(target);
      if(mapVector[x][y]->isOccupied()) partcount  + incrementvalue;
		}
	}

}

/*

Funkcja getSurroundings() zwraca vector liczb calkowitych ktorych index
odpowiada miejscu dookola czasteczki na przykladzie ponizej

- - - - - - -
| 1 | 2 | 3 |
| - | - | - |
| 4 | 0 | 5 |
| - | - | - |
| 6 | 7 | 8 |
- - - - - - -
*/

// do poprawy
std::vector<int> Map::getSurroundings(int x, int y) {
	std::vector<int> surroundingsVector(9, 0);
	if (x == mapWidth && y == mapHeight) {
		surroundingsVector.at(3) = 1; // 3
		surroundingsVector.at(5) = 1; // 5
		surroundingsVector.at(8) = 1; // 8
		surroundingsVector.at(7) = 1; // 7
		surroundingsVector.at(6) = 1; // 6

		if (mapVector[x - 1][y - 1]->isOccupied())
			surroundingsVector.at(1) = 1; // 1
		if (mapVector[x][y - 1]->isOccupied())
			surroundingsVector.at(2) = 1; // 2
		if (mapVector[x - 1][y]->isOccupied())
			surroundingsVector.at(4) = 1; // 4
		return surroundingsVector;
	}
	if (x == 0 && y == mapHeight) {
		surroundingsVector.at(1) = 1; // 1
		surroundingsVector.at(4) = 1; // 4
		surroundingsVector.at(6) = 1; // 6
		surroundingsVector.at(7) = 1; // 7
		surroundingsVector.at(8) = 1; // 8
		if (mapVector[x][y - 1]->isOccupied())
			surroundingsVector.at(2) = 1; // 2
		if (mapVector[x + 1][y - 1]->isOccupied())
			surroundingsVector.at(3) = 1; // 3
		if (mapVector[x + 1][y]->isOccupied())
			surroundingsVector.at(5) = 1; // 5

		return surroundingsVector;
	}

	if (x < mapWidth && y < mapHeight && x > 0) {
		if (mapVector[x - 1][y - 1]->isOccupied())
			surroundingsVector.at(1) = 1; // 1
		if (mapVector[x][y - 1]->isOccupied())
			surroundingsVector.at(2) = 1; // 2
		if (mapVector[x + 1][y - 1]->isOccupied())
			surroundingsVector.at(3) = 1; // 3
		if (mapVector[x - 1][y]->isOccupied())
			surroundingsVector.at(4) = 1; // 4
		if (mapVector[x + 1][y]->isOccupied())
			surroundingsVector.at(5) = 1; // 5
		if (mapVector[x - 1][y + 1]->isOccupied())
			surroundingsVector.at(6) = 1; // 6
		if (mapVector[x][y + 1]->isOccupied())
			surroundingsVector.at(7) = 1; // 7
		if (mapVector[x + 1][y + 1]->isOccupied())
			surroundingsVector.at(8) = 1; // 8
		return surroundingsVector;
	}
	if (x == 0) {
		surroundingsVector.at(1) = 1; // 1
		surroundingsVector.at(4) = 1; // 4
		surroundingsVector.at(6) = 1; // 6

		if (mapVector[x][y - 1]->isOccupied())
			surroundingsVector.at(2) = 1; // 2
		if (mapVector[x + 1][y - 1]->isOccupied())
			surroundingsVector.at(3) = 1; // 3
		if (mapVector[x + 1][y]->isOccupied())
			surroundingsVector.at(5) = 1; // 5
		if (mapVector[x][y + 1]->isOccupied())
			surroundingsVector.at(7) = 1; // 7
		if (mapVector[x + 1][y + 1]->isOccupied())
			surroundingsVector.at(8) = 1; // 8
		return surroundingsVector;
	}
	if (x == mapWidth) {
		surroundingsVector.at(3) = 1; // 3
		surroundingsVector.at(5) = 1; // 5
		surroundingsVector.at(8) = 1; // 8
		if (mapVector[x - 1][y - 1]->isOccupied())
			surroundingsVector.at(1) = 1; // 1
		if (mapVector[x][y - 1]->isOccupied())
			surroundingsVector.at(2) = 1; // 2
		if (mapVector[x - 1][y]->isOccupied())
			surroundingsVector.at(4) = 1; // 4
		if (mapVector[x - 1][y + 1]->isOccupied())
			surroundingsVector.at(6) = 1; // 6
		if (mapVector[x][y + 1]->isOccupied())
			surroundingsVector.at(7) = 1; // 7
		return surroundingsVector;
	}
	if (y == mapHeight) {
		surroundingsVector.at(6) = 1; // 6
		surroundingsVector.at(7) = 1; // 7
		surroundingsVector.at(8) = 1; // 8

		if (mapVector[x - 1][y - 1]->isOccupied())
			surroundingsVector.at(1) = 1; // 1
		if (mapVector[x][y - 1]->isOccupied())
			surroundingsVector.at(2) = 1; // 2
		if (mapVector[x + 1][y - 1]->isOccupied())
			surroundingsVector.at(3) = 1; // 3
		if (mapVector[x - 1][y]->isOccupied())
			surroundingsVector.at(4) = 1; // 4
		if (mapVector[x + 1][y]->isOccupied())
			surroundingsVector.at(5) = 1; // 5
		return surroundingsVector;
	}
	return surroundingsVector;
}

/*
Funkcja zamienia cząsteczki miejscami na ekranie oraz w vektorze 2d planszy

Funkcja pobiera indeksy x oraz y vectora 2d, oraz oraz liczbe pól o którą ma
przestawić cząstki
*/

void Map::switchPlaces(int x, int y, int xdiff, int ydiff) {
	Particlea *part = mapVector[x + xdiff][y + ydiff];
	mapVector[x + xdiff][y + ydiff] = mapVector[x][y];
	mapVector[x + xdiff][y + ydiff]->setPosition(
		x * cellSize, (y + ydiff) * cellSize);
	mapVector[x][y] = part;
	mapVector[x][y]->setPosition(x * cellSize, y * cellSize);
}




