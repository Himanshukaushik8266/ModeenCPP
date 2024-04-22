#include<iostream>
#include<functional>
#include<mutex>
#include<thread>
#include<array>
using FnType=std::function<void(void)>;
using FunctionContainer=std::array<FnType,3>;
using ThreadContainer=std::array<std::thread,3>;

std::mutex mt;

void CreateObjects(FunctionContainer &data){
    data[0]=[](){
        std::lock_guard<std::mutex> lg(mt);
        std::cout<<"Phela function"<<std::endl;
    };  
    data[1]=[](){
        std::lock_guard<std::mutex> lg(mt);
        std::cout<<"Dusra Fucntion"<<std::endl;
    };

    data[2]=[](){
        std::lock_guard<std::mutex> lg(mt);
        std::cout<<"Teersa Function"<<std::endl;
    };
}


void CreateThreads(ThreadContainer & threads, FunctionContainer &data){
   for(int i=0;i<3;i++){
    threads[i]=std::thread(data[i]);
   }
}

void JoinThreads(ThreadContainer& threads){
    for(int i=0;i<3;i++){
        if(threads[i].joinable()){
            threads[i].join();
        }
    }
}

int main(){
    FunctionContainer data;
    ThreadContainer data2;


    CreateObjects(data);
    CreateThreads(data2,data);
    JoinThreads(data2);
    return 0;

}