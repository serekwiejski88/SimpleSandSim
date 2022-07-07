#ifndef WATERPARTICLE_H
#define WATERPARTICLE_H
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "Particlea.h"

class waterParticle : public Particlea
{
    public:
        // Konstruktory i destruktory
        waterParticle();
        waterParticle(int posX, int posY, float size);
         ~waterParticle();
        // Funkcje publiczne
        int move(std::vector<int> surroundingsVector);
        bool isOccupied();
    protected:


    private:

};
#endif