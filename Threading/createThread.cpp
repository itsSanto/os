#include <thread>

void foo(int a)
{
    (void)a;
}

int main()
{

    std::thread threadObj(foo, 10);

    const int a = 10;
    std::thread threadObj2([&a]()
                           { (void)a; });
    if (threadObj.joinable())
    {
        threadObj.join();
    }
    if (threadObj2.joinable())
    {
        threadObj2.join();
    }
    return 0;
}