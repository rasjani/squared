#ifndef YOSHIENT2_H
#define YOSHIENT2_H
#include "entity.h"


class YoshiEnt2 : public Entity {
    public:
        YoshiEnt2(std::string image, int frames);

        virtual void think(const int& elapsedTime);


    private:
        int startX;
        int startY;
        int endX;
        int endY;
};

#endif
