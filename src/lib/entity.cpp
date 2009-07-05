#include "entity.h"
#include "surfacemanager.h"
#include "engine.h"



Entity::Entity(std::string image, int frames) :
    _x(0),
    _y(0),
    _width(0),
    _height(0),
    surface(0)
{
    UNUSED(frames);
    SurfaceManager *cm = SurfaceManager::getInstance();
    surfaceId = cm->addImage(new Surface(image));
    surface = cm->getImage(surfaceId);
}


Entity::~Entity() {
    // Surfaces are deleted by SurfaceManager
}


void Entity::think(const int& elapsedTime) {
    UNUSED(elapsedTime);
}

void Entity::render(SDL_Surface *destSurface) {
    UNUSED(destSurface);
}
