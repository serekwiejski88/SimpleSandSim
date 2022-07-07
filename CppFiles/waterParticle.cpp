#include "waterParticle.h"

// Konstruktory i destruktory

waterParticle::waterParticle() {
}

waterParticle::waterParticle(int posX, int posY, float size) {
	particle.setPosition(posX, posY);
	particle.setSize(sf::Vector2f(size, size));
	particle.setFillColor(sf::Color::Blue);
}

waterParticle::~waterParticle() {
	// dtor
}

/*
Funkcja move podejmuje decyzje w którą stronę chce poruszyć się cząsteczka
zwracajac int odpowiadajacy polu jak nizej

- - - - - - -
| 1 | 2 | 3 |
| - | - | - |
| 4 | 0 | 5 |
| - | - | - |
| 6 | 7 | 8 |
- - - - - - -
*/

int waterParticle::move(std::vector<int> surroundingsVector) {
	int random = rand() % 2;
	if (surroundingsVector.at(7) == 0)
		return 7;
	if (surroundingsVector.at(6) == 0)
		return 6;
	if (surroundingsVector.at(8) == 0)
		return 8;
  if (surroundingsVector.at(4) == 0 && surroundingsVector.at(5) == 0){
    if(random == 1) return 4;
    if (random == 0) return 5;
  }
  if (surroundingsVector.at(4) == 0)
		return 4;
  if (surroundingsVector.at(5) == 0)
		return 5;

	return 2;
}

bool waterParticle::isOccupied() {
	return 1;
}