#include <iostream>
#include <array>
#include<functional>
#include <thread>

void Square(std::array<int, 5> &data)
{
    for (int i : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Square of this number is :" << i * i << std::endl;
    }
}
void Cube(std::array<int, 5> &data)
{
    for (int i : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Cube of this number is :" << i * i * i << std::endl;
    }
}
int main()
{

    /*
        Main thread start creates an array object on local stack memory
    */
    std::array<int,5> a {65,34,22,77,97};
    //We launch thread
    /*
        A thread is a mini program, As the developer, t1 object is a "handle" for me to interact with the 
        thread in some way . This t1 is attached to Square mini program We have also passed "data" by reference
        which is required by the Square function
    */
    std::thread t1(&Square,std::ref(a));

    /*
        A thread is a mini program, As the developer, t2 object is a "handle" for me to interact with the 
        thread in some way . This t2 is attached to Cube mini program We have also passed "data" by reference
        which is required by the Square function
    */
    std::thread t2(&Cube,std::ref(a));



    //Signal as a Result / Summary / Satisfaction

    /*
        ***************JOIN**************************

        Waiting for the thread to complete 
    */ 


   t1.join();   //main will not proceed to next line until t1 is finised 
   t2.join();   //main will not proceed to next line until t2 is finised

   std::cout<<"Good bye \n";
    return 0;

}

/*      
    Traditional Way



                                                                    ----------------------->Cube() ends
                                                                    |                           |
                                                                    |                           |   
    The program starts                                              |                           |
    --------------->Square()                    ----------->Cube() starts                       |-------stops!!!
                        |                       |
                        |                       |
                        |                       |
                        |                       |
                        ------------------>Sqaure() ends



    Alternate Way:


                        ------------Square starts---------------------Square ends
                       /
                      /
                     / 
                    /
    ---------->Starts
                    \
                     \
                      \
                       \
                        ---------------cube starts-------------------- Cube ends
*/

/*
    t1.join() and t1 crashes ---------> still report to main ------>signal sent
                    t1 does finish even before t2 starts
                    t2 already finished before t.join even started

*/