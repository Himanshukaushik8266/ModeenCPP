#ifndef BILL_H
#define BILL_H
#include<functional>
#include <ostream>
#include "Invoice.h"

class Bill
{
private:
    /* data */
    float _amount;
    std::reference_wrapper<Invoice> _invoice;
public:
    Bill()=default;
    Bill(const Bill &)=delete;
    Bill(Bill && )=delete;
    Bill & operator=(const Bill & )=delete;
    Bill &operator=(Bill &&)=delete;
    ~Bill()=default;

    Bill(float amount,std::reference_wrapper<Invoice> invoice):_amount{amount},_invoice{invoice}{}

    friend std::ostream &operator<<(std::ostream &os, const Bill &rhs) {
        os << "_amount: " << rhs._amount
           << " _invoice: " << rhs._invoice;
        return os;
    }
};

#endif // BILL_H
