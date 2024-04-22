#include "Functionalities.h"
#include <array>

using TArr = std::array<std::thread, 3>;
using FArr = std::array<FReturn, 3>;

int main()
{
    VehicleType data;
    TArr th;
    FArr fn;
    CreateObject(data);
    fn[0] = DisplayObject;
    fn[1] = UnCommonData;
    fn[2] = CommonData;

    for(int i=0;i<3;i++){
        th[i] = std::thread(fn[i], std::ref(data));
    }
    for(int i=0;i<3;i++)
    {
        if(th[i].joinable())
        {
            th[i].join();
        }
    }
}