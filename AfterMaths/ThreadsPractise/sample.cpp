#include<iostream>
#include "NullPointerException.h"
#include "NullPointerFutureError.h"


void Display(int *arr){
    std::cout<<*arr<<std::endl;
}

int main(){

    int arr[5]{1,2,6,4,5};
    
    Display(arr);

    try{
        throw NullPointerFutureError(std::future_errc::broken_promise,"This is Future error");
        throw NullPointerException("Null Pointer Encountered!!");
    }
    catch(NullPointerException & ex){
        std::cout<<ex.what()<<std::endl;
    }
    catch(std::future_error &ex){
        std::cout<<ex.what()<<std::endl;
    }



    return 0;

}