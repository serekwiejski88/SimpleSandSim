
#ifndef PARTICLEA_H
#define PARTICLEA_H
#include "SFML-2.5.1/include/SFML/Graphics.hpp"

class Particlea
{
    public:
        virtual ~Particlea() {};
        // Funkcje publicnze
        void setPosition(int x, int y);
        int getPositionx();
        int getPositiony();
        void render(sf::RenderTarget *target);

        // Funkcje wirtualne
        virtual int move(std::vector<int> surroundingsVector) = 0;
        virtual bool isOccupied()=0;

    protected:
        
        sf::RectangleShape particle;

    private:

};

#endif // PARTICLEA_H

