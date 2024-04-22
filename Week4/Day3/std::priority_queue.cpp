#include<iostream>
#include<queue>
#include<vector>

struct Less_Comparator
{
    /* data */
    bool operator()(int a,int b){
        return a>b;
    }
}check;

//min heap: a,b : a will be before b in min heap if a is less than b
//max head: a,b : a will be before b in max heap if a is greater than b


int main(){

    int a=10,b=1;4;

    std::cout<<std::boolalpha<<check(a,b)<<std::endl;

    std::vector<int> data {11,10,22,7,9,15,27,18};

    std::priority_queue<int,std::vector<int>,Less_Comparator> pq(data.begin(),data.end());

    while(!pq.empty()){
        std::cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;

}