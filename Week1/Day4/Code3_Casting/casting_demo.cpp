#include <iostream>

class ParentClass
{
private:
    /* data */
public:
    ParentClass() {}
    virtual ~ParentClass() {}
    virtual void magic() = 0;
};
class Child : public ParentClass
{
private:
public:
    Child() {}
    ~Child() {}

    void childDisplay()
    {
        std::cout << "Child Class" << std::endl;
    }
    void magic() override
    {
        std::cout << "magic from child" << std::endl;
    }
};
int main()
{

    float f1 = 10.21f;
    // int n1=(float)f1;   //C style casting sometime missbehave on compile time we can't perform if cast successfull do this or that
    // std::cout<<n1<<"\n"; //Lossy conversion //10

    /*************************************************************************************************/

    // STATIC CAST

    // int n1=65;
    // char c=static_cast<char>(n1);

    //  std::cout<<c<<"\n";

    // TYPE 2 : CAST WHEN PARENT-CHILD RUNTIME POLYMORPHISM IS IN PICTURE(DYNAMIC CAST)

    // 2A : CONVERTING Pointers

        ParentClass * ptr=new Child();
        ptr->magic();//ptr type is parent but there is a virtual function (compiler will find the most derived version of that function)
        
        Child * c=dynamic_cast<Child *> (ptr);
        if(c!=nullptr){
            c->childDisplay();
        }
        delete c;

        //if conversion fails it will set nullptr to the target


    // 2B : CONVERTING Reference
        ParentClass * tt=new Child();

        Child & ch=dynamic_cast<Child &> (*tt);


        ch.childDisplay();

        delete tt;
    return 0;
}