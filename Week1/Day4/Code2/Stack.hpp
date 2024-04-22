#ifndef STACK_HPP
#define STACK_HPP

#include <list>
#include <ostream>
#include "StackEmptyException.hpp"

template <typename T>
class Stack
{
private:
    std::list<T> _data{};

public:
    Stack() = default;
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;
    Stack(Stack &&) = default;
    Stack &operator=(Stack &&) = default;
    ~Stack() = default;

    void Pop()
    {
        if (_data.empty())
        {
            throw StackEmptyException("Data is empty");
        }

        _data.pop_back();
    }

    /*
        Push function accepts one item "val" of type T
        return void;
    */

    void Push(T val);
    T Peek();
    size_t Size()
    {
        return _data.size();
    }
    bool IsEmpty()
    {
        return _data.empty();
    }
};

template <typename T>
inline void Stack<T>::Push(T val)
{
    _data.push_back(val);
}

template <typename T>
inline T Stack<T>::Peek()
{
    if (_data.empty())
    {
        throw StackEmptyException("Data is empty");
    }
    return _data.back();
}

#endif // STACK_HPP




/*
    Integer can be both negative as well as positive

    we can take unsigned int

    unsigned long 2^64 positive numbers ------> (size_t)

*/