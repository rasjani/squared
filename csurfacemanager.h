#ifndef CSURFACEMANAGER_H
#define CSURFACEMANAGER_H

#include <vector>
#include <string>
#include "csurface.h"

class CSurfaceManager {
    public:
        CSurfaceManager();
        ~CSurfaceManager();

        bool addImage(CSurface *image);
        CSurface *getImage(std::string name);

    private:
        std::vector<CSurface *> *images;

};

#endif // CSURFACEMANAGER_H
