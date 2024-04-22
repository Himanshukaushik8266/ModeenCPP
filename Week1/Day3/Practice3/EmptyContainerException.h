#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H
#include <iostream>
#include<cstring>

class EmptyContainerException : public std::exception
{
private:
    char * _message;
public:
    EmptyContainerException() =default;
    EmptyContainerException(const EmptyContainerException&)=delete;
    EmptyContainerException(const EmptyContainerException&&)=delete;
    EmptyContainerException & operator =(const EmptyContainerException &)=delete;
    EmptyContainerException & operator=(const EmptyContainerException &&)=delete;


    EmptyContainerException(const char * message){
        _message=new char[strlen(message) +1];

        strcpy(_message,message);
    }


    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return _message;
    }



    ~EmptyContainerException() {
        delete [] _message;
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H
