/*
    Producer Consumer problem !

    2 workers in your program :-

    1_ may produce "Something"
    2_ will "Consume it" (process the produced item)

    We need to write a program where thread is waiting for an event to happen in second thread to perform its action.
*/
/*
    2 threads(2 workers)
        -> main thread(producer) : take input and "make value available"
        -> Operation(t1) (Consumer) : Once a signal is received from main to indicate input received calculate the sqaure


        a) Programmer calculates how many workers are required and triggers them at a time [thread pooling!]

        b) t1 may want to do some other work even before data input is received
*/

#include <iostream>
#include <thread>
#include <condition_variable> //--------------->Production level semaphore to capture signal
#include <mutex>
int value = 0;
bool flag = false;
std::mutex mt;
std::condition_variable cv;

void Operation()
{
    int *ans = (int *)malloc(sizeof(int));
    ////////////////////////////////////// ------------>wating line
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul,[&](){return flag;});

    *ans = value * value;
    std::cout << "Sqaure of " << value << " is : " << *ans << std::endl;

    free(ans);
}

void takeInput(){
    std::lock_guard<std::mutex> lg(mt);
    std::cin >> value;
}

int main()
{

    std::thread t1(&Operation);
    takeInput();
    flag = true;
    cv.notify_one();
    t1.join();

    return 0;
}