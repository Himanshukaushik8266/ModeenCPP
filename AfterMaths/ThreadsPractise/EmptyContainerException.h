#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class EmptyContainerException : public std::exception
{
private:
    /* data */
    char *_msg;

public:
    EmptyContainerException() = default;
    EmptyContainerException(const EmptyContainerException &) = delete;
    EmptyContainerException(EmptyContainerException &&) = delete;
    EmptyContainerException &operator=(const EmptyContainerException &) = delete;
    EmptyContainerException &operator=(EmptyContainerException &&) = delete;
    ~EmptyContainerException()
    {
        delete[] _msg;
    };

    EmptyContainerException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    virtual const char *
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg;
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H
