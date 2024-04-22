#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include<iostream>
#include<stdexcept>
#include<cstring>

class NullPointerException : public std::exception
{
private:
    /* data */
    char * _msg;
public:
    NullPointerException()=default;
    NullPointerException(const NullPointerException &)=delete;
    NullPointerException(NullPointerException &&)=delete;
    NullPointerException & operator =(const NullPointerException &)=delete;
    NullPointerException & operator =(NullPointerException &&)=delete;

    NullPointerException(const char * msg){
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }

    ~NullPointerException(){
        delete [] _msg;
    }

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg;
    }
};

#endif // NULLPOINTEREXCEPTION_H
