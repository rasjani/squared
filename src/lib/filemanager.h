#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

#include "singleton.h"

/**
 * @brief FileManager ... short description ...
 * @author Jani Mikkonen <ext-jani.3.mikkonen@nokia.com>
 * @date 2009-06-30
 * ... description ...
 */

class FileManager : public Singleton<FileManager> {

        friend class Singleton<FileManager>;
    protected:

        /**
         * Default constructor - private, this is singleton class
         */
        FileManager();

    public:

        /**
         * @brief adds extra path to search paths
         *
         * @param path  Directory to add into search path
         *
         * @return false if path doesnt exist or unable to add path, true on success
         **/
        bool addSearchPath(std::string fileName);

        /**
         * @brief tries to locate given file from each entry in search path
         *
         * @param file
         *
         * @return std::string with full path to the file, 0 on failure
         **/
        std::string *searchFile(std::string file);

        /**
         * Destructor
         */
        virtual ~FileManager();

    private:
        std::vector<std::string> *paths;
    protected:

    private:
        bool exists(std::string *name);
};

#endif /* #ifndef FILEMANAGER_H */
