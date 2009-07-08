#ifndef SINGLETON_H
#define SINGLETON_H

#include "support.h"

#define DECLARE_SINGLETON(n) friend class Singleton<n>
#define INIT_SINGLETON(n) template <> n* Singleton<n>::sInstance = 0
#define INSTANCEOF(n) n::getInstance()
#define INSTANCEPTROF(n) n::getInstancePointer()
#define CONSTINSTANCE n::getConstInstance()

template < typename T>
class Singleton {

    private:
        static T *sInstance;

    protected:
        Singleton() { };
        Singleton(T* instancePointer) {
            Singleton::sInstance= instancePointer; 
        }
        Singleton(const Singleton &);
        Singleton& operator=(const Singleton&);
        ~Singleton()  { };

    public:

        static T *getInstancePointer() {
            if ( ISREALLYNULL(sInstance) ) {
                Singleton::sInstance = new T;
            }
            return  Singleton::sInstance;
        }

        static T &getInstance() {
            if ( ISREALLYNULL(sInstance) ) {
                Singleton::sInstance = new T;
            }
            return *Singleton::sInstance;
        }
        static const T *getConstInstance() {
             return *getInstance();            
        };

};




#endif
