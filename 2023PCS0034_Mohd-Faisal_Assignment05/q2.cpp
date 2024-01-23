#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex3;

void thread1()
{
    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 1 acquired lock1\n";
    std::cout << "Now trying to acquire lock on mutex 3....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock3(mutex3);
    std::cout << "Thread 1 acquired lock3\n";
}

void thread2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 2 acquired lock1\n";
}

void thread3()
{
    std::unique_lock<std::mutex> lock3(mutex3);
    std::cout << "Thread 3 acquired lock3\n\n";
    std::cout << "Now trying to acquire lock on mutex 1....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 3 acquired lock1\n";
}

void thread4()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::unique_lock<std::mutex> lock3(mutex3);
    std::cout << "Thread 4 acquired lock3\n";
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread t3(thread3);
    std::thread t4(thread4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
