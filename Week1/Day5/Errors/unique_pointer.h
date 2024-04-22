#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

template <typename T>
class unique_pointer
{
private:
    T * _mptr;

public:
    unique_pointer(T * ptr):_mptr{ptr}{
        ptr=nullptr;

    };
    unique_pointer(const T* &)=delete;
    unique_pointer & operator =(const T* &)=delete;

    unique_pointer(const T* &&)=delete;
    unique_pointer & operator =(const T* &&)=default;

    void Release(){
        delete _mptr;
        _mptr=nullptr;
    }

    ~unique_pointer(){
        delete _mptr;
        _mptr=nullptr;
    }
    

};


#endif // UNIQUE_POINTER_H
