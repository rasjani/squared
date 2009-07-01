#include "filemanager.h"
#include "engine.h"
#include <sys/stat.h>
#include <iostream>

FileManager *FileManager::fmInstance = 0;

FileManager::FileManager() :
    paths(0)
{
    paths = new std::vector<std::string>();
}

FileManager::~FileManager() {
    if (paths != 0) {
        delete paths;
        paths = 0;
    }
    FileManager::fmInstance = 0;
}

FileManager *FileManager::getInstance() {
    if (!FileManager::fmInstance) {
        FileManager::fmInstance = new FileManager();
    }
    return FileManager::fmInstance;
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
  if(intStat == 0) {
    return true;
  } else {
    return false;
  }
}
