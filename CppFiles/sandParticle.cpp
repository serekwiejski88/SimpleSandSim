#include "sandParticle.h"

sandParticle::sandParticle() {
}

sandParticle::sandParticle(int posX, int posY, float size) {
	particle.setPosition(posX, posY);
	particle.setSize(sf::Vector2f(size, size));
	particle.setFillColor(sf::Color(255,255,0,255));
}

sandParticle::~sandParticle() {
	// dtor
}

/*
Funkcja move podejmuje decyzje w którą stronę chce poruszyć się cząsteczka zwracajac int odpowiadajacy polu jak nizej

- - - - - - -
| 1 | 2 | 3 |
| - | - | - |
| 4 | 0 | 5 |
| - | - | - |
| 6 | 7 | 8 |
- - - - - - -
*/

int sandParticle::move(std::vector<int> surroundingsVector) {
	if (surroundingsVector.at(7)==0) 
		  return 7;
	if (surroundingsVector.at(6)==0)
			return 6;
	if (surroundingsVector.at(8)==0)
			return 8;
	return 7;
}

bool sandParticle::isOccupied() {
	return 1;
}