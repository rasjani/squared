#ifndef SURFACEMANAGER_H
#define SURFACEMANAGER_H

#include <vector>
#include <string>
#include "surface.h"

class SurfaceManager {
    private:
        SurfaceManager();

    public:        
        ~SurfaceManager();

        static SurfaceManager *getInstance();
        int addImage(Surface *image);
        Surface *getImage(int imageId);

    protected:
        static SurfaceManager *manager;
    private:
        std::vector<Surface *> *images;

};

#endif // SURFACEMANAGER_H
