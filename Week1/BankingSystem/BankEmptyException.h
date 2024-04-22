#ifndef BANKEMPTYEXCEPTION_H
#define BANKEMPTYEXCEPTION_H
#include<cstring>
#include<stdexcept>
class BankEmptyException:std::exception
{
private:
    /* data */
    char * _msg;
public:
    BankEmptyException()=default;
    BankEmptyException(const BankEmptyException &)=delete;
    BankEmptyException(const BankEmptyException &&)=delete;
    BankEmptyException & operator=(const BankEmptyException&)=delete;
    BankEmptyException & operator=(const BankEmptyException&&)=delete;

    BankEmptyException(const char * msg){
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    ~BankEmptyException() {
        delete [] _msg;
    }


    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg;
    }
};

#endif // BANKEMPTYEXCEPTION_H
