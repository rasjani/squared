#include "yoshient.h"
#include "cengine.h"
#include <cmath>

static double direction = 0.010;
#define PI 3.14159265

/*
static double CosineInterpolate(
    double y1,double y2,
    double mu)
{
    double mu2;
    mu2 = (1-cos(mu*PI))/2;
    return(y1*(1-mu2)+y2*mu2);
}
 */



YoshiEnt::YoshiEnt(std::string image, int frames) :
    CEntity(image,frames),
    startX(50),
    startY(50),
    endX(613),
    endY(398),
    betweenX(100),
    betweenY(10)
{
    _x = 50;
    _y = 50;

    surface->setTransparency(255,0,255);
}


void YoshiEnt::think(const int& elapsedTime) {
    CEntity::think(elapsedTime);
    static double mu = 0.0; 
    static double k = 0.5;

    mu = mu + direction;

    if (mu > 1.0) {
        direction = -0.010;
        mu = 1.0;
    }  else if (mu<0.0) {
        direction = 0.010;
        mu = 0.0;
    }
    // interpolatex= x1 + mu * (x2-x1) + k*mu*(1-mu)*(y1-y2)
    // interpolatey= y1 + mu * (y2-y1) + k*mu*(1-mu)*(x2-x1)
    _x = (int) startX + mu * (endX-startX) + k + mu* (1-mu) * (startY-endY);
    _y = (int) startY + mu * (endY-startY) + k * mu * (1-mu) * (endX-startX);

}
void YoshiEnt:: render(SDL_Surface *destSurface) {
   surface->drawPartial(destSurface,_x,_y,0,_frame*64,64,64);  
}
