#include "surfacemanager.h"
#include "yoshient2.h"
#include "engine.h"
#include <cmath>

static double direction = 0.010;

YoshiEnt2::YoshiEnt2(std::string image, int frames) :
        Entity(image,frames),
        startX(100),
        startY(323),
        endX(150),
        endY(400) {
    _x = 100;
    _y = 323;
    SurfaceManager *cm = INSTANCEPTROF(SurfaceManager);
    Surface *another = new Surface("yoshi2.bmp",8,AnimationManager::AnimSingle);
    another -> setTransparency(255,0,255);


    addSurface(cm->addImage( another ));
    getActiveSurface()->setTransparency(255,0,255);
}


void YoshiEnt2::think(const int& elapsedTime) {
    Entity::think(elapsedTime);
    static double mu = 0.0;
    static double k = 0.95;

    mu = mu + direction;

    if (mu > 1.0) {
        setActiveSurfaceId(1);
        direction = -0.010;
        mu = 1.0;
    }  else if (mu<0.0) {
        setActiveSurfaceId(0);
        direction = 0.010;
        mu = 0.0;
    }

    // interpolatex= x1 + mu * (x2-x1) + k*mu*(1-mu)*(y1-y2)
    // interpolatey= y1 + mu * (y2-y1) + k*mu*(1-mu)*(x2-x1)
    _x = (int) startX + mu * (endX-startX) + k + mu* (1-mu) * (startY-endY);

    _y = (int) startY + mu * (endY-startY) + k * mu * (1-mu) * (endX-startX);

}
