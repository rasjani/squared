#include "entity.h"
#include "surfacemanager.h"
#include "support.h"



Entity::Entity(std::string image, int frames, int height, int width, AnimationManager::animStyle aStyle) :
    _x(0),
    _y(0),
    frameHeight(height),
    frameWidth(width),
    surfaces(0)
{
    SurfaceManager *cm = SurfaceManager::getInstance();
    surfaces = new std::vector<int>();
    surfaces->push_back( cm->addImage(new Surface(image,frames,aStyle)) );
    setActiveSurfaceId(0);
}


Entity::~Entity() {
    // Individual Surfaces are deleted by SurfaceManager 

    if (surfaces != 0) {
        delete surfaces;
        surfaces = 0;
    }
}


Surface *Entity::getActiveSurface() {
    SurfaceManager *cm = SurfaceManager::getInstance();
    return cm->getImage(surfaces->at(activeSurfaceId));
}
void Entity::think(const int& elapsedTime) {
    UNUSED(elapsedTime);
    getActiveSurface()->animate();
}

void Entity::render(SDL_Surface *destSurface) {
    Surface *s = getActiveSurface();
    s->drawPartial(destSurface,_x,_y,0,s->getCurrentFrame()*frameHeight,frameWidth, frameHeight);
}


bool Entity::addSurface(int newSurfaceId) {
    surfaces->push_back( newSurfaceId );
    return false;    
}


bool Entity::setActiveSurfaceId(int surfaceId) {
    activeSurfaceId = surfaceId;
    getActiveSurface()->resetClass();
    return false;
}
