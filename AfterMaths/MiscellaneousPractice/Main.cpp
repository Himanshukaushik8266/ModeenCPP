#include "Functionalities.h"
#include <future>
#include <algorithm>
#include<numeric>


int main()
{
    std::future<std::optional<Container>> t1 = std::async(&Function1);

    std::optional<Container> data;

    try
    {
        data = t1.get();
    }
    catch (std::runtime_error &re)
    {
        std::cout << re.what() << std::endl;
    }

    if (data.has_value())
    {
        Container temp = data.value();

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cout << temp[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    else
    {
        std::cout << "Null signal found" << std::endl;
    }

    int *a = new int[10];
    std::cout << "Enter Element in 1D array : " << std::endl;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }

    std::cout << "Sum of all the elements in 1D array is : " << sum << std::endl;


    std::cout<<"Array is : "<<*a<<std::endl;


    char * name=new char[10];
    std::cout<<"Enter the name of the customer : ";
    std::cin>>name;

    std::cout<<"The name of the passenger is : "<<name <<std::endl;

    std::cout<<sizeof(name)<<std::endl;


    std::cout<<"This is the demo for Array of pointers : "<<std::endl;

    std::vector<MeriClass *> v={new MeriClass(),new MeriClass(),new MeriClass(),new MeriClass(),new MeriClass()};

    std::cout<<"Enter values for n for 5 MeriClass Pointer Objects : "<<std::endl;

    for(int i=0;i<5;i++){
        int enter;
        std::cin>>enter;
        v[i]->setN(enter);
    }   

    std::vector<int> vec{1,3,4,5,56,6};

    std::cout<<std::accumulate(v.begin(),v.end(),0,[](int upto_this,const MeriClass *c){
        return upto_this+c->getN();
    })<<std::endl;


    return 0;
}

