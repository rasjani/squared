#include "filemanager.h"
#include <sys/stat.h>

FileManager *FileManager::_instance = NULL;

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
}

FileManager *FileManager::getInstance() {
    if (!FileManager::_instance) {
        FileManager::_instance = new FileManager();
    }
    return FileManager::_instance;
}

bool FileManager::addSearchPath(std::string path) {
    if (paths != 0) {
        if (exists(path)) {
            paths->push_back(path);
            return true;
        }
    } 
    return false;
}

std::string FileManager::searchFile(std::string) {
    // TODO: Implement
    return 0;
}

bool FileManager::exists(std::string name) {
  struct stat fileInfo;
  int intStat;

  intStat = stat(name.c_str(),&fileInfo);
  if(intStat == 0) {
    return true;
  } else {
    return false;
  }
}
