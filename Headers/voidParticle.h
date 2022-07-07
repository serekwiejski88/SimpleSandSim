#ifndef VOIDPARTICLE_H
#define VOIDPARTICLE_H
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "Particlea.h"

class voidParticle : public Particlea
{
    public:
        // Konstruktory i destruktory
        voidParticle();
        voidParticle(int posX, int posY, float size);
        virtual ~voidParticle();
        // Funkcje publiczne
        int move(std::vector<int> surroundingsVector);
        bool isOccupied();
    protected:


    private:
        
};
#endif