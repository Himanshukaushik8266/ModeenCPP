#include<iostream>
#include<functional>
void magic(int &ref){

}
int main(){

    int data=10;
    std::reference_wrapper<int> refWrap{data};
    magic(refWrap);

    //Reference wrapper can implicitly decay into normal reference
    //But now we can store reference wrapper into an array or in a vector as well.

    std::reference_wrapper<int> arr[]{refWrap}; 
}