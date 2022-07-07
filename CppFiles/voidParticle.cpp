#include "Particlea.h"
#include "voidParticle.h"

voidParticle::voidParticle()
{
}

voidParticle::voidParticle(int posX, int posY, float size)
{
    particle.setPosition(posX, posY);
}

voidParticle::~voidParticle()
{
    //dtor
}
int voidParticle::move(std::vector<int> surroundingsVector){
  return 0;
}
bool voidParticle::isOccupied(){return 0;}