#include<iostream>
#include<vector>
/*
    Data passed to magic must always be temporary values or moved values 
*/
void Magic(std::vector<int> && data){       // && capture parameter by rvalue

}

int main(){

    std::vector<int> value{10,20,30,40,50};

    Magic(std::move(value));

    return 0;

}

/*
    We create vector in main (scope main)
    HEAP
    [10,20,30,40,50, ............. ]
    ^              ^               ^
    |              |               |
    |              |               |
    |              |               |
    |              |               |
    start          last            Capacity
    pointer        pointer         pointer

    <---------Main wala ------------>
    <----------24 bytes------------->
*/



/*
    Sequence of events:-
        -> Program Starts because OS schedules the process

        -> main function is executed as a thread by OS

        -> Vector of integer values is created in scope of main
            ->  Heap allocation mapping and vector gets space on heap

            ->  Pointers to start , end and capacity are recorded in the vector 
                objects "value" in main

        -> Magic is called with std::move(value)
            ->  It converts lvalue to rvalue 
                (tells the compiler "value" vector can be prepared for move)

            ->  Now vector value is treated as a rvalue 
                so Magic(std::move(value)) 
                becomes Magic(std::vector<int>{10,20,30,40,50})

*/ 