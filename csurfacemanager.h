#ifndef CSURFACEMANAGER_H
#define CSURFACEMANAGER_H

#include <vector>
#include <string>
#include "csurface.h"

class CSurfaceManager {
    private:
        CSurfaceManager();

    public:        
        ~CSurfaceManager();

        static CSurfaceManager *getInstance();
        int addImage(CSurface *image);
        CSurface *getImage(int imageId);

    protected:
        static CSurfaceManager *manager;
    private:
        std::vector<CSurface *> *images;

};

#endif // CSURFACEMANAGER_H
