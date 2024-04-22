#include "Functionalities.h"

#include <future>

int main()
{

    Container data;
    CreateObjects(data);

    std::future<bool> f1 = std::async(&AreAllStudentPass, std::ref(data));

    bool result;

    try
    {
        result = f1.get();
    }
    catch (std::runtime_error &re)
    {
        std::cout << re.what() << std::endl;
        return 0;
    }

    std::cout << "Is all the student passed overall  : " << std::boolalpha << result << std::endl;

    return 0;
}