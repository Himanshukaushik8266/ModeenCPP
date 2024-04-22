#include<iostream>
#include<functional>
#include<list>

void Adaptor(std::function<void(std::list<int> &)> fn, std::list<int> &li){
    fn(li);
}

auto fns=[](std::list<int>& li)->void {
    for(int i:li){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
};

int main(){
    std::list<int> li{1,2,4,6};
    auto fnNew=std::bind(fns,std::list<int> {4,5,6,8,4});
    fnNew();
    return 0;

}