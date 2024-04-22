#ifndef INVOICE_H
#define INVOICE_H
#include <ostream>

class Invoice
{
private:
    /* data */
    int _number;

public:
    Invoice()=default;
    Invoice(const Invoice &)=delete;
    Invoice(Invoice && )=default;
    Invoice & operator=(const Invoice & )=delete;
    Invoice &operator=(Invoice &&)=delete;
    ~Invoice()=default;

    Invoice(int number):_number{number}{}

    friend std::ostream &operator<<(std::ostream &os, const Invoice &rhs) {
        os << "number: " << rhs._number;
        return os;
    }
};

#endif // INVOICE_H
