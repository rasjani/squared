#include <centitymanager.h>


CEntityManager::CEntityManager() 
: 
    entities(0)
{
    entities = new std::vector<CEntity*>();
}


CEntityManager::~CEntityManager() {
    if (entities != 0) {
        std::vector<CEntity*>::iterator it;
        while(!entities->empty()) {
            CEntity *ent = 0;
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

int CEntityManager::addEntity(CEntity *ent) {
    if (entities != 0 && ent != 0) {
        // TODO: What if vector is full or insert fails for some reason ?
        entities->push_back(ent);
        return entities->size()-1;
    } else  
        return -1;
}


void CEntityManager::think(const int& elapsedTime) {
    std::vector<CEntity*>::iterator it;
    for ( it = entities -> begin() ; it != entities -> end() ; it ++ ) {
        (*it) -> think(elapsedTime);
    }
}


void CEntityManager::render(SDL_Surface *destSurface) {
    std::vector<CEntity*>::iterator it;
    for ( it = entities -> begin() ; it != entities -> end() ; it ++ ) {
        (*it) -> render(destSurface);
    }
}
