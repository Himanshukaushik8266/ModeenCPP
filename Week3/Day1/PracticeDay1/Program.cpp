#include<iostream>
#include<array>
#include<vector>
#include<functional>
#include<thread>
using FnType=std::function<void(int)>;
using FunctionContainer=std::array<FnType,3>;
using InputContainer=std::array<int,5>;
using ResultContainer=std::array<int,15>;
using ThreadContainer=std::array<std::thread,3>;




void CreateFunctions(FunctionContainer &fns,InputContainer &input,ResultContainer &result){
    fns[0]=[&](int index){
        for(int t:input){
            result[index++]=t*t;
        }
    };
    fns[1]=[&](int index){
        for(int i:input){
            result[index++]=i*i*i;
        }
    };

    fns[2]=[&](int index){
        
        for(int i:input){
            int fac=1;
            for(int j=i;j>=1;j--){
                fac*=j;
            }
            result[index++]=fac;
        }
    };

}

void CreateThreads(FunctionContainer &fns , ThreadContainer & threads){
    int ind[3]={0,5,10};
    for(int i=0;i<3;i++){
        threads[i]=std::thread(fns[i],ind[i]);
    }
}


void JoinThreads(ThreadContainer &threads){
    for(std::thread &t: threads){
        if(t.joinable()){
            t.join();
        }
    }
}


void DisplayResult(const ResultContainer &result){
    for(int const i:result){
        // std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}


int main(){

    //Input
    FunctionContainer fns;
    InputContainer input{1,2,3,4,5};
    ResultContainer result;
    ThreadContainer threads;

    CreateFunctions(fns,input,result);
    CreateThreads(fns,threads);
    JoinThreads(threads);
    DisplayResult(result);

    return 0;

}