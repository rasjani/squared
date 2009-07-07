#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <SDL.h>
#include <vector>
#include "surface.h"
#include "tasks.h"
#include "animationmanager.h"

class Entity : public Tasks {
    public:
        Entity(std::string image, int frames = 1, int height=64, int width=64, AnimationManager::animStyle astyle=AnimationManager::AnimLoop);

        virtual ~Entity();

        virtual void think(const int& elapsedTime);
        virtual void render(SDL_Surface *destSurface);

        bool addSurface(int newSurfaceId);
        bool setActiveSurfaceId(int surfaceId);

        Surface *getActiveSurface();

    protected:
        int _x;
        int _y;
        int frameHeight;
        int frameWidth;
        int  activeSurfaceId;

        std::vector<int> *surfaces;


};

#endif /* #ifndef ENTITY_H */
