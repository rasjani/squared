#ifndef LOGGER_H
#define LOGGER_H

/**
 * @brief Logger ... short description ...
 * @author Jani Mikkonen <ext-jani.3.mikkonen@nokia.com>
 * @date 2009-07-06
 * ... description ...
 */

#include <fstream>
#include <iostream>


/*
#define LOG(n) Logger::getInstance()->output(__FILE__,__FUNCTION__,__LINE__,n)

*/

#define LOG(n) Logger::getInstance()->output(__FILE__,__FUNCTION__,__LINE__,n)

class Logger {
    private:

        /**
         * Default constructor
         */
        Logger(char *fil);

    public:
        void output(const char* filename, const char *function, int lineno, const char* logline);

        static Logger* getInstance(char *file=NULL);

        /**
         * Destructor
         */
        virtual ~Logger();


    private:

        static Logger *_instance;
        std::ofstream *out;

};

#endif /* #ifndef LOGGER_H */
