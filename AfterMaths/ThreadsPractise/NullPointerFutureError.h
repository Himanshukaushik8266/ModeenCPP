#ifndef NULLPOINTERFUTUREERROR_H
#define NULLPOINTERFUTUREERROR_H
#include<future>
#include<iostream>
#include<cstring>

class NullPointerFutureError:public std::future_error
{
private:
    /* data */
    char* _msg;
public:
    NullPointerFutureError()=default;
    NullPointerFutureError(const NullPointerFutureError &)=delete;
    NullPointerFutureError(NullPointerFutureError && )=delete;
    NullPointerFutureError & operator=(const NullPointerFutureError &)=delete;
    NullPointerFutureError & operator=(NullPointerFutureError && )=delete;


    NullPointerFutureError(std::future_errc ec,const char * msg): future_error(ec){
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }


    virtual const char* what() const noexcept{
        return _msg;
    }

    ~NullPointerFutureError(){
        delete [] _msg;
    }
};

#endif // NULLPOINTERFUTUREERROR_H
