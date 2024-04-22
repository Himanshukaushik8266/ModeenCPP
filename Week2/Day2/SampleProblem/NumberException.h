#ifndef NUMBEREXCEPTION_H
#define NUMBEREXCEPTION_H
#include<stdexcept>
#include<cstring>


class NumberException:public std::exception
{
private:
    /* data */
    char *_msg;

public:
    NumberException() = default;
    NumberException(const NumberException &) = delete;
    NumberException(NumberException &&) = default;
    NumberException &operator=(const NumberException &) = delete;
    NumberException &operator=(const NumberException &&) = delete;
    ~NumberException(){
        delete [] _msg;
    };
    NumberException(const char *msg){
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg;
    }
    

};
#endif // NUMBEREXCEPTION_H
