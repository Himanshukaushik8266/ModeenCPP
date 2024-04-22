/*
    Processor : It is the hardware device based on silicon(ATLEAST TILL TODAY) which executes instructions given
                eg. Intel i5 12 gen 1230U

    **Systems level programmer must has a good understanding of the hardware.

    Core: It is a section of the processor which is capable of executing ONE WHOLE PROCESS.

    [ c1     |   c2    ]
    [ c3     |   c4    ]



    More core-----------------> More isolation --------------> More processes we can run.

    **(We had wrote Single thread, Single process, Syncronous programs!)

*/
/*
    Delays : IO Delay, CPU bound delay !!

*/

#include <iostream>
#include <array>
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
    std::array<int,5> a {65,34,22,77,97};
    Square(a);
    Cube(a);
    return 0;
}