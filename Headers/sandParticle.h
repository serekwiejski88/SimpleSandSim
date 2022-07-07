#ifndef SANDPARTICLE_H
#define SANDPARTICLE_H
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "Particlea.h"

class sandParticle : public Particlea
{
    public:
        //Komstruktory i destruktory
        sandParticle();
        sandParticle(int posX, int posY, float size);
         ~sandParticle();
        // Funkcje publiczne
        int move(std::vector<int> surroundingsVector);
        bool isOccupied();
    protected:


    private:

};
#endif