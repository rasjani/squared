#include "surfacemanager.h"
#include <iostream>
#include <stdexcept>


SurfaceManager *SurfaceManager::manager = NULL;

SurfaceManager::SurfaceManager() :
        images(0) {
    images = new std::vector<Surface *>();
}

SurfaceManager *SurfaceManager::getInstance() {
    if (!SurfaceManager::manager) {
        SurfaceManager::manager = new SurfaceManager();
    }

    return SurfaceManager::manager;
}

int SurfaceManager::addImage(Surface *image) {
    if (image != 0 && images != 0) {
        images->push_back(image);
        return images->size()-1;
    }

    return -1;
}


Surface *SurfaceManager::getImage(int imageId) {
    if (images != 0) {
        Surface *s = 0;

        try  {
            s = images->at(imageId);
        } catch (std::out_of_range &e) {

        }

        return s;
    }

    return 0;
}


SurfaceManager::~SurfaceManager() {
    // TODO: We are propably leaking memory here ?
    if (images != 0) {
        std::vector<Surface *>::iterator it;

        while (!images->empty() ) {
            Surface *tmp  = 0;
            it = images->begin();
            tmp = (*it);
            images->erase(it);
            delete tmp;
        }

        delete images;

        images = 0;
    }
}

