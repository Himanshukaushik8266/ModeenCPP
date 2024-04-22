#include <iostream>
class Complex
{
private:
    int real{0};
    int imaginary{0};

public:
    Complex()
    {
        std::cout << "Constructor called!!" << std::endl;
    };
    Complex(const Complex &) = delete;
    Complex(Complex &&) = delete;
    Complex &operator=(const Complex &) = delete;
    Complex &operator=(Complex &&) = delete;
    ~Complex() = default;


    Complex(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    int getReal() const { return real; }

    int getImaginary() const { return imaginary; }

    void setReal(int real_) { real = real_; }

    /*****************************New and Delete Operator Overload*******************************/
    static void *operator new(size_t s)
    {
        std::cout << "Hamare wala" << std::endl;
        return (void *)malloc(s);
    }
    static void operator delete(void *pp)
    {
        std::cout << "Yeh mera delete" << std::endl;
        free(pp);
    }
    /********************************Subscript Operator Overload**********************************/

    Complex* operator[](int i)
    {
        this->real=this->real*i;
        return this;
    }
    /****************************Functor Overload**************************************************/
    void operator()()
    {
        std::cout << "This is function calling" << std::endl;
    }

    /*****************************Plus Operator (3 different overloads)******************************/

    Complex *operator+(const Complex &c)
    {
        Complex *cc = new Complex(this->real + c.getReal(), this->imaginary + c.getImaginary());
        return cc;
    }

    Complex *operator+(int i)
    {
        std::cout << "imaginary" << std::endl;
        this->imaginary = this->imaginary + i;
        return this;
    }

    friend Complex *operator+(int a, Complex &c)
    {
        std::cout << "real part" << std::endl;
        c.setReal(c.getReal() + a);
        return &c;
    }
    /************************Ostream Overload******************************************/
    friend std::ostream &operator<<(std::ostream &os, const Complex &rhs)
    {
        os << "real: " << rhs.real
           << " imaginary: " << rhs.imaginary;
        return os;
    }
};

int main()
{
    Complex *number = new Complex(10, 5);

    Complex *imaginaryChange = (*number) + 10;
    std::cout << *imaginaryChange << std::endl;
    Complex *realChange = 10 + (*number);
    std::cout << *realChange << std::endl;

    Complex *newnumber = (*imaginaryChange) + (*realChange);

    std::cout << *newnumber << std::endl;

    std::cout<<*((*(*number)[10])[30])<<std::endl;


    delete number;

    return 0;
}