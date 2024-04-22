#ifndef ACCOUNTNOTFOUNDEXCEPTION_H
#define ACCOUNTNOTFOUNDEXCEPTION_H
#include<cstring>
#include<stdexcept>
class AccountNotFoundException:std::exception
{
private:
    /* data */
    char * _msg;
public:
    AccountNotFoundException()=default;
    AccountNotFoundException(const AccountNotFoundException &)=delete;
    AccountNotFoundException(const AccountNotFoundException &&)=delete;
    AccountNotFoundException & operator=(const AccountNotFoundException&)=delete;
    AccountNotFoundException & operator=(const AccountNotFoundException&&)=delete;

    AccountNotFoundException(const char * msg){
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    ~AccountNotFoundException() {
        delete [] _msg;
    }


    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg;
    }
};

#endif // ACCOUNTNOTFOUNDEXCEPTION_H
