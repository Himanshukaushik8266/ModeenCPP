#include<iostream>
#include<future>
#include <algorithm>
#include <numeric>


using Array = std::array<int ,5>;
int FactorialResult[5];
Array Fact;
int inputContainer[5];

void ComputeFactorial(std::future<Array>& ft){
    std::array<int, 5> arr1 = ft.get();
    std::for_each(arr1.begin(), arr1.end(), [](int val){
        std::cout<<val<<"\n";
    });
    int ind=0;
    std::for_each(
        arr1.begin(),
        arr1.end(),
        [&](int ans)
        {
            int val=1;
            for(int i=2;i<=ans;i++)
            {
                val*=i;
            }
            Fact[ind++] = val;
        }
    );

    for(int i : Fact)
    {
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}

void takeInput(){
    std::promise<Array> pr;
    std::future<Array> ft = pr.get_future();
    std::array<int, 5> arr{1,2,3,4,5};

    std::future<void> f2 = std::async(&ComputeFactorial, std::ref(ft));
    pr.set_value(arr);
    f2.wait();
}

int main(){

    
    std::future<void> f1 = std::async(&takeInput);

    f1.wait();
    return 0;

}