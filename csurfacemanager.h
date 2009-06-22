#ifndef CSURFACEMANAGER_H
#define CSURFACEMANAGER_H

#include <vector>
#include <string>
#include "csurface.h"

class CSurfaceManager {
    public:
        CSurfaceManager();
        ~CSurfaceManager();

        int addImage(CSurface *image);
        CSurface *getImage(int imageId);

    private:
        std::vector<CSurface *> *images;

};

#endif // CSURFACEMANAGER_H
