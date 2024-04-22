/*
    create an array of 3 threads

        -thread 1 should sqaure of each number in thre array and store in a result
            array(position 1 to 5)
        -thread 2 should calculate cube of each number in the array and store in a 
            result array(position 6 to 10)
        -thread 3 should calculate factorial of each number in the array and store 
            in a result array(position 11 to 15)

        Assumption : number in the input array will be between 1 to 10;
*/

#include<thread>
#include<iostream>
#include<array>

int main(){
    std::array<int,14> result;
    std::array<int,7> input{1,2,3,4,5,8,9};
    int i=0;
    int k=7;
    int j=10;

    std::array<std::thread,2> arr{
        std::thread([&](){
            for(int t:input){
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            result[i]=t*t;
            i++;

            }
            
        }),
        std::thread([&](){
            int cube=0;
            for(int t:input){
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                cube=t*t*t;
            result[k]=cube;
            k++;
            }
            
        })
    };

    for(std::thread &t :arr){
        if(t.joinable()){
            t.join();
        }
    }

    for(int t:result){
        std::cout<<t<<" ";
    }
    std::cout<<"\n";

}