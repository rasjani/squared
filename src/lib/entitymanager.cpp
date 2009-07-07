#include "entitymanager.h"


EntityManager::EntityManager() :
        entities(0) {
    entities = new std::vector<Entity*>();
}


EntityManager::~EntityManager() {
    if (entities != 0) {
        std::vector<Entity*>::iterator it;

        while (!entities->empty()) {
            Entity *ent = 0;
            it = entities->begin();
            ent = (*it);
            entities->erase(it);
            delete ent;
            ent = 0;
        }

        delete entities;
        entities = 0;
    }
}

int EntityManager::addEntity(Entity *ent) {
    if (entities != 0 && ent != 0) {
        // TODO: What if vector is full or insert fails for some reason ?
        entities->push_back(ent);
        return entities->size()-1;
    } else
        return -1;
}


void EntityManager::think(const int& elapsedTime) {
    std::vector<Entity*>::iterator it;

    for ( it = entities -> begin() ; it != entities -> end() ; it ++ ) {
        (*it) -> think(elapsedTime);
    }
}


void EntityManager::render(SDL_Surface *destSurface) {
    std::vector<Entity*>::iterator it;

    for ( it = entities -> begin() ; it != entities -> end() ; it ++ ) {
        (*it) -> render(destSurface);
    }
}
