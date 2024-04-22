/*
  std::ref and std::cref are the shortcuts to create std::reference wrapper
    std::ref do something similar to the & symobol before any parameter or argument passed
    std::cref is constant reference creator and cannot be mutated

*/

#include<iostream>
#include<functional>
void magic(int &a){
    ++a;
}

int main(){

    int a=0;
    auto binded_magic=std::bind(magic,std::placeholders::_1);  
    /*
        In bind even though we are sending "a" as reference by default still the function not chaning the value of a 
        as we thought it should

        to overcome this we have to use std::ref before sending a directly to the binded function 

        But if we are using placeholders as we are doing conventionally then the given argument is passing by reference 
        and we are getting the desired output

        this shows that the bind functions argument are making a copy by default without specifying whether to pass them as a 
        reference 

        BTW std::ref is nothing but shorhand of writing the reference wrapper 

                                Also

        ALL THE ALGORITHM TAKES THEIR CALLABLE PARAMETERS BY COPY HENCE WE HAVE TO MENTION THEM AS REFERENCED BEFORE PERFORMING
        SOME TASK WITH THEM 

            EG. 
                std::for_each(data.begin(),data.end(),"Some callable") ;

                    this callable must be marked using std::ref() or by creating a referene wrapper to avoid copy
    */
    binded_magic(a);
    binded_magic(a);
    std::cout<<a<<std::endl;
    return 0;

}