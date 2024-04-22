#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H
#include<stdexcept>
#include<cstring>


class NullPointerException:public std::exception
{
private:
    /* data */
    char *_msg;

public:
    NullPointerException() = default;
    NullPointerException(const NullPointerException &) = delete;
    NullPointerException(NullPointerException &&) = default;
    NullPointerException &operator=(const NullPointerException &) = delete;
    NullPointerException &operator=(const NullPointerException &&) = delete;
    ~NullPointerException(){
        delete [] _msg;
    };
    NullPointerException(const char *msg){
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg;
    }
    

};
#endif // NULLPOINTEREXCEPTION_H
