#ifndef SURFACEMANAGER_H
#define SURFACEMANAGER_H

#include <vector>
#include <string>
#include "surface.h"
#include "singleton.h"

class SurfaceManager : public Singleton<SurfaceManager> {
        DECLARE_SINGLETON(SurfaceManager);
    private:
        SurfaceManager();

    public:
        ~SurfaceManager();

        int addImage(Surface *image);
        Surface *getImage(int imageId);

    private:
        std::vector<Surface *> *images;

};

#endif // SURFACEMANAGER_H
