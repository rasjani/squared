#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP


#include <vector>
#include "tasks.h"
#include "entity.h"

class EntityManager : public Tasks {
    public:
        EntityManager();
        ~EntityManager();

        int addEntity(Entity *ent);

        virtual void think(const int& elapsedTime);
        virtual void render(SDL_Surface *destSurface);

    private:
        std::vector<Entity *> *entities;

};

#endif /* #ifndef ENTITYMANAGER_H */
