#ifndef STACKEMPTYEXCEPTION_HPP
#define STACKEMPTYEXCEPTION_HPP
#include<stdexcept>
#include<cstring>
class StackEmptyException:std::exception
{
private:
    /* data */
    char * _message;
public:
    StackEmptyException()=delete;

    StackEmptyException(const StackEmptyException&)=delete;
    StackEmptyException& operator=(const StackEmptyException&)=delete;
    StackEmptyException(StackEmptyException&&)=default;
    StackEmptyException& operator=(StackEmptyException&&)=delete;


    explicit StackEmptyException(const char * msg){
        _message=new char[strlen(msg)+1];
        strcpy(_message,msg);
    }

    ~StackEmptyException(){
        delete [] _message;
    }
    virtual const char * what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _message;
    }
};

#endif // STACKEMPTYEXCEPTION_HPP
