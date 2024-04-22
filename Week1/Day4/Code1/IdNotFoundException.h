#ifndef IdNotFoundException_H
#define IdNotFoundException_H
#include<stdexcept>
#include<cstring>
class IdNotFoundException :public std::exception
{
private:
    char * _msg;
public:
    
    IdNotFoundException() =delete;
    IdNotFoundException (const IdNotFoundException &) =delete;                  //(delete -> disabled copy constructor )
    IdNotFoundException(IdNotFoundException &&)=default;                         //brand new
    IdNotFoundException &operator=(const IdNotFoundException&)=delete;          //deleted copy assignment
    IdNotFoundException && operator=(IdNotFoundException&&)=delete;  

    IdNotFoundException(const char * msg) {
        // strlen(msg)

        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }
    ~IdNotFoundException() {
        delete [] _msg;
    }


    virtual const char * what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // IdNotFoundException_H
