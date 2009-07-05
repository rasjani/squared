#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <SDL/SDL.h>

#include "surface.h"
#include "tasks.h"
#include "animationmanager.h"

class Entity : public Tasks
{
  public:
    Entity(std::string image, int frames);

    virtual ~Entity();

    virtual void think(const int& elapsedTime);
    virtual void render(SDL_Surface *destSurface);

  protected:
    int _x;
    int _y;
    int _width;
    int _height;
    int  surfaceId;

    Surface *surface;

};

#endif /* #ifndef ENTITY_H */
