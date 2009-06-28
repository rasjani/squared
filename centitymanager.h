#ifndef CENTITYMANAGER_HPP
#define CENTITYMANAGER_HPP


#include <vector>

#include "centity.h"

class CEntityManager
{
  public:
    CEntityManager();
    ~CEntityManager();

    int addEntity(CEntity *ent);

    void think(const int& elapsedTime);
    void render(SDL_Surface *destSurface);

  private:
    std::vector<CEntity *> *entities;

};

#endif /* #ifndef CENTITYMANAGER_H */
