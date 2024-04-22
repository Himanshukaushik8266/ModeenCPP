/*
    withdraw :  withdraw takes 10 units of money from amount.
    deposit : adds 10 units of money to amount

    RUN withdraw and deposit BOTH FOR 100 TIMES EACH on an initial amount of 1000;

    what will be the final amount after 200 transactions are completed?

*/

#include<iostream>
#include<thread>
#include<mutex>
int amount=1000;
std::mutex mt;
void withdraw(){
    for(int i=0;i<100;i++){

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        mt.lock();
        amount-=10;
        mt.unlock();
    }
}
void deposit(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        mt.lock();
        amount+=10;
        mt.unlock();
    }
}

int main(){

    std::thread t1(&withdraw);
    std::thread t2(&deposit);

    t1.join();
    t2.join();


    std::cout<<"Final amount is : "<<amount<<std::endl;

    return 0;

}