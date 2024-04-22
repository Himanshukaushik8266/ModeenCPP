/*
    ***************************************BIND***************************************************************

    Some problems related to software industry
    ->  We can not massively change code when it is deployed to the client
    ->  Sometimes API parameters need to be fixed at a certain value
        eg. Connect(ip,port hostname,id,password)

            Can we run it with 3 parameter ??
                Connect(port hostname, id,password) // ip is set to some value and port as well

    ->  Bind help us to set default values for some pre made function parameter without changing original one




    function variable store the address of the first instruction
*/

#include <iostream>
#include <functional>
#include<cstring>
#include <list>
void Formula(const int x, const int y, const int z)
{
    std::cout << "Answer is : " << (x + y) - z << "\n";
}

void Magic(const std::list<int> &data, int n)
{
    for (int val : data)
    {
        n--;
        if (n == 0)
        {
            std::cout << val << "\n";
        }
    }
}
int main()
{

    Formula(10, 20, 30);

    // set the value x in formula to 100 fixed forever!

    auto binded_formula = std::bind(&Formula, 100, std::placeholders::_1, std::placeholders::_2);

    binded_formula(30, 40);


    auto binded_magic=std::bind(&Magic,std::placeholders::_2, std::placeholders::_1);

    auto binded_strcpy=std::bind(&strcpy,std::placeholders::_2,std::placeholders::_1);

    char* msg=new char[100];
    binded_strcpy("Himanshu",msg);
    std::cout<<msg<<std::endl;
    delete [] msg;


    auto fun=[](int number,int factor){std::cout<<number*factor<<std::endl;};
    auto binded_lambda_fn=std::bind(fun,std::placeholders::_1,40);    //Don't use address of the function when binding lambda functions.
    
    binded_lambda_fn(10);
    
    
    return 0;
}


/*****************************************************ashish.rawat@kpit.com***********************************************/
