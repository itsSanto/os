#include <vector>
#include <iostream>
#include <thread>

std::vector<int> myVec;

void addToVec(int max, int interval)
{
    for (int i = 0; i <= max; ++i)
    {
        if (0 == i % interval)
        {
            myVec.push_back(i);
        }
    }
}

void printVec()
{
    for (const auto &ele : myVec)
    {
        std::cout << ele << " ";
    }
}

int main()
{
    int max = 1000;
    std::thread t1(addToVec, max, 1);
    std::thread t2(addToVec, max, 4);
    std::thread t3(printVec);

    if (t1.joinable())
    {
        t1.join();
    }
    if (t2.joinable())
    {
        t2.join();
    }
    if (t3.joinable())
    {
        t3.join();
    }
    return 0;
}