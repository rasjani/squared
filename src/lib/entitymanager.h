#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP


#include <vector>

#include "entity.h"

class EntityManager
{
  public:
    EntityManager();
    ~EntityManager();

    int addEntity(Entity *ent);

    void think(const int& elapsedTime);
    void render(SDL_Surface *destSurface);

  private:
    std::vector<Entity *> *entities;

};

#endif /* #ifndef ENTITYMANAGER_H */
