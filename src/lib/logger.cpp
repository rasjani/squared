#include "logger.h"
#include "support.h"
#include <iostream>


Logger *Logger::_instance = 0;


Logger *Logger::getInstance(char *file) {
    if (!Logger::_instance) {
        Logger::_instance = new Logger(file);
    }

    return Logger::_instance;
}

Logger::Logger(char *file) :
        out(0) {
    if (ISREALLYNULL(file)) {
        // TODO: This is not portable! What would be the right
        // way to open stdout ?
        out = new std::ofstream();
        out->open("/dev/stdout", std::ios_base::app|std::ios_base::out);
    } else {
        out = new std::ofstream();
        out->open(file, std::ios_base::app|std::ios_base::out);
    }

    output("------.---","----",0,"Start Session");

}



Logger::~Logger() {
    output("------.---","----",0,"End Session");
    out->close();
    delete out;
    out = 0;
    Logger::_instance = 0;
}

void Logger::output(const char* filename, const char* function, int lineno, const char* logline) {
    if (out!=0) {
        // (filename.c:102) Function: Logfile
        *out << "(" << filename << ":" << lineno << ") " << function << "(): " << logline << std::endl;
    }
}

