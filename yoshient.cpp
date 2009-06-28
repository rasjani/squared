#include "yoshient.h"
#include "cengine.h"

static int direction = 1;


YoshiEnt::YoshiEnt(std::string image, int frames) :
    CEntity(image,frames) 
{
    _x = 50;
    _y = 50;

    surface->setTransparency(255,0,255);
}


void YoshiEnt::think(const int& elapsedTime) {
    CEntity::think(elapsedTime);
    _x += direction;
    if (_x>=500) {
        direction = -1;
    } else if (_x<=50)  { 
        direction = 1;
    }
}
void YoshiEnt:: render(SDL_Surface *destSurface) {
   surface->drawPartial(destSurface,_x,_y,0,_frame*64,64,64);  
}
