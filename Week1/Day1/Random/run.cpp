#include<bits/stdc++.h>

class Dummy
{
private:
    int _id;
    int _salary;
public:
    Dummy(int id,float salary) :_id{id},_salary{salary}{}
    ~Dummy() =default;
};
int main(){

    //Scenario 1 : const with non pointer primitive variable
    const int n1=10;    // n1 is constant integer
    int const n2=20;    //n2 is a const integer

    //Scenario 2 : pointer with primitive
    int n3=99;
    int n4=188;
    //2a
        
        const int * ptr =&n3; //ptr is a pointer to a const int (Compiler bluf)

        //*ptr =77 //this will give error

        //but......

        ptr=&n4; //THIS IS OKAY
    
    //2b

        int * const ptr2=&n3;//ptr2 is a constant pointer and it vant point to another object;

        *ptr2=100;  //THIS IS OKAY


        //But ......
        
        //ptr2=&n4  //NOT OKAY


    //2c

        const int * const ptr3=&n3; //Ptr3 is a const pointer to a constant integer
        //*ptr3=18; //NOT OKAY
        //ptr=&n4;  //NOT OKAY


    //Scenario 3  : Const on a stack object

        const Dummy d1(101,67000.0f);

    //Scenario 4: when const is used in member function 

        // getter functions
         /*
            This function is safe for const object as well. Only a function that is marked as const is const object safe.
         */

    return 0;

}