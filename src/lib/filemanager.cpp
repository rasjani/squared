#include "filemanager.h"
#include "support.h"
#include <sys/stat.h>
#include <iostream>

// FileManager *FileManager::fmInstance = 0;
//
//

INIT_SINGLETON(FileManager);

FileManager::FileManager() :
        paths(0) {
    paths = new std::vector<std::string>();
}

FileManager::~FileManager() {
    if (paths != 0) {
        delete paths;
        paths = 0;
    }

//    FileManager::fmInstance = 0;
}

bool FileManager::addSearchPath(std::string path) {
    if (paths != 0) {
        if (exists(&path)) {
            paths->push_back(path);
            return true;
        }
    }

    return false;
}

// TODO: Where to fetch portable file separator ?
#define DIRECTORY_SEPARATOR "/"
std::string *FileManager::searchFile(std::string fileName) {
    std::vector<std::string>::iterator it;
    UNUSED(fileName);

    for (it = paths->begin(); it != paths->end(); it ++ ) {
        std::string *fullPath = new std::string( *it + DIRECTORY_SEPARATOR + fileName );

        if (exists(fullPath)) {
            return fullPath;
        } else {
            delete fullPath;
        }
    }

    return 0;
}

bool FileManager::exists(std::string *name) {

    struct stat fileInfo;
    int intStat;

    intStat = stat(name->c_str(),&fileInfo);

    if (intStat == 0) {
        return true;
    } else {
        return false;
    }
}
