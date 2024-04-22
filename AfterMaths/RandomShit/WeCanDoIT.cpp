#include<iostream>
#include<algorithm>
#include<numeric>


int main(){
    std::vector<int> vec{1,2,3,4,5,5,6};
    std::vector<int>::iterator  itr= vec.begin();

    std::advance(itr,vec.size()-5);

    std::vector<int> result;
    



    std::vector<int>::reverse_iterator  it= vec.rbegin();
    std::advance(it,vec.size()-5);

    std::next(vec.rbegin());

    std::for_each(it,vec.rend(),[&](int i){std::cout<<i<<"\t";});


    std::cout<<"\n";



    return 0;
}