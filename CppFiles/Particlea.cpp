#include "Particlea.h"
#include "iostream"


// Funkcja setPosition ustawia pozycje czasteczki

void Particlea::setPosition(int x, int y) {
	particle.setPosition(x, y);
}

// Funkcja getPositionx zwraca pozycje x czasteczki

int Particlea::getPositionx() {
	return (int)particle.getPosition().x;
}

// Funkcja getPositiony zwraca pozycje y czasteczki
int Particlea::getPositiony() {
	return (int)particle.getPosition().y;
}

// Funkcja render wyswietla czasteczke na ekranie
void Particlea::render(sf::RenderTarget *target) {
	target->draw(particle);
}
