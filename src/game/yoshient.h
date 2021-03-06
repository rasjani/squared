#ifndef YOSHIENT_H
#define YOSHIENT_H
#include "entity.h"


class YoshiEnt : public Entity {
    public:
        YoshiEnt(std::string image, int frames);

        virtual void think(const int& elapsedTime);

    private:
        int startX;
        int startY;
        int endX;
        int endY;
        int betweenX;
        int betweenY;
};

#endif
