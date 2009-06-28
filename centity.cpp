#include "centity.h"
#include "csurfacemanager.h"
#include "cengine.h"



CEntity::CEntity(std::string image, int frames) :
    _x(0),
    _y(0),
    _width(0),
    _height(0),
    _frame(0),
    animControl(0),
    surface(0)
{
    CSurfaceManager *cm = CSurfaceManager::getInstance();
    animControl = new CAnimation();
    animControl->setMaxFrames(frames);

    surfaceId = cm->addImage(new CSurface(image));
    surface = cm->getImage(surfaceId);


}


CEntity::~CEntity() {
    // Surfaces are deleted by SurfaceManager
    if (animControl != 0)  {
        delete animControl;
        animControl = 0;
    }
}


void CEntity::think(const int& elapsedTime) {
    UNUSED(elapsedTime);
    if (animControl != 0) {
        animControl->animate();
    }
    _frame = animControl->getCurrentFrame();
}

void CEntity::render(SDL_Surface *destSurface) {
    UNUSED(destSurface);
}
