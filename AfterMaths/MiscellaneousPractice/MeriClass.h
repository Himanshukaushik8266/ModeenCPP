#ifndef MERICLASS_H
#define MERICLASS_H

class MeriClass
{
private:
    /* data */
    int n{0};
public:
    MeriClass(/* args */) {}
    ~MeriClass() {}

    int getN() const { return n; }
    void setN(int n_) { n = n_; }
}; 

#endif // MERICLASS_H
