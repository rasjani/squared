#include "entity.h"
#include "surfacemanager.h"
#include "engine.h"



Entity::Entity(std::string image, int frames) :
    _x(0),
    _y(0),
    _width(0),
    _height(0),
    _frame(0),
    animControl(0),
    surface(0)
{
    SurfaceManager *cm = SurfaceManager::getInstance();
    animControl = new AnimationManager();
    animControl->setMaxFrames(frames);
    animControl->setAnimStyle(AnimationManager::AnimLoop);
    surfaceId = cm->addImage(new Surface(image));
    surface = cm->getImage(surfaceId);
}


Entity::~Entity() {
    // Surfaces are deleted by SurfaceManager
    if (animControl != 0)  {
        delete animControl;
        animControl = 0;
    }
}


void Entity::think(const int& elapsedTime) {
    UNUSED(elapsedTime);
    if (animControl != 0) {
        animControl->animate();
    }
    _frame = animControl->getCurrentFrame();
}

void Entity::render(SDL_Surface *destSurface) {
    UNUSED(destSurface);
}
