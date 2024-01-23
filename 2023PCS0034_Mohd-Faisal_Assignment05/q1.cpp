#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex2, mutex3;

void thread1()
{
    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 1 acquired lock1" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock2(mutex2);
    std::cout << "Thread 1 acquired lock2" << std::endl;
}

void thread2()
{
    std::unique_lock<std::mutex> lock2(mutex2);
    std::cout << "Thread 2 acquired lock2" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock3(mutex3);
    std::cout << "Thread 2 acquired lock3" << std::endl;
}

void thread3()
{
    std::unique_lock<std::mutex> lock3(mutex3);
    std::cout << "Thread 3 acquired lock3" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 3 acquired lock1" << std::endl;
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread t3(thread3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
