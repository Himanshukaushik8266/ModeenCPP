/*
    Reference Wrapper:

        No.             Identifier name         Address     Content             Alternate names
        1                   n1                  0x99H           99              ref,argref
        2                   data                0x18H           10              r1,r2
*/


#include<iostream>
void magic (int &argRef){

}
int main(){
    int n1=99;
    int &ref=n1; //creating a reference

    magic(n1);

    int data =10;
    int &r1=data;
    int &r2=r1; //Creating reference of a reference (It is creating one more alternate name for original data )
 
}
/*
        A refernce does not present in the ram there is no memory block associated with a referece (just an alternate name )
        We cannot make the container for referneces !!
        They cannot be treated as value.


        previously:
            A Pointer when stored internally in an object creates representation of a pointer (Smart pointer)
        Now:
            A reference when stored internally in an object creates representation of reference called (reference_wrapper)
*/

