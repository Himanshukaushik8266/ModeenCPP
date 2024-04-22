#ifndef LOWBALANCEEXCEPTION_H
#define LOWBALANCEEXCEPTION_H

#include<cstring>
#include<stdexcept>
class LowBalanceException:std::exception
{
private:
    /* data */
    char * _msg;
public:
    LowBalanceException()=default;
    LowBalanceException(const LowBalanceException &)=delete;
    LowBalanceException(const LowBalanceException &&)=delete;
    LowBalanceException & operator=(const LowBalanceException&)=delete;
    LowBalanceException & operator=(const LowBalanceException&&)=delete;

    LowBalanceException(const char * msg){
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    ~LowBalanceException() {
        delete [] _msg;
    }


    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg;
    }
};


#endif // LOWBALANCEEXCEPTION_H
