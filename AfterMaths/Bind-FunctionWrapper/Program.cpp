#include <iostream>
#include <functional>
#include<queue>
#include<vector>

int FirstLevel(int c)
{
    return c;
}
int SecondLevel(int b, int c)
{
    auto fn = std::bind(&FirstLevel, c);
    return b + fn();
}
int ThirdLevel(int a, int b, int c)
{
    auto fn2 = std::bind(&SecondLevel, b, std::placeholders::_1);
    return a + fn2(c);
}

std::function<void(int)> fn = [](int a)
{
    std::cout << "Hello friends my name is himanshu kaushik with a as : " << a << "\n";
};

std::function<void(void)> bindedFunction = std::bind(fn, 10);


auto Comprator1=[](const int a, const int b){
    return a<b;
}; //min heap


auto Comparator2=[](const int a, const int b){
    return a>b;
};//max heap



int main()
{

    auto fn3 = std::bind(&ThirdLevel, 10, std::placeholders::_1, std::placeholders::_2);

    std::cout << fn3(14, 15) << "\n";

    bindedFunction();

    std::vector<int> vec{156,53,23,865,3,7};

    std::priority_queue<int,std::vector<int>,decltype(Comprator1)> pq1(vec.begin(),vec.end(),Comprator1);

    while (!pq1.empty()){
        std::cout<<pq1.top()<<std::endl;
        pq1.pop();
    }
    std::cout<<"************************************************\n";

    std::priority_queue<int,std::vector<int>,decltype(Comparator2)> pq2(vec.begin(),vec.end(),Comparator2);
    while(!pq2.empty()){
        std::cout<<pq2.top()<<std::endl;
        pq2.pop();
    }

    return 0;
}