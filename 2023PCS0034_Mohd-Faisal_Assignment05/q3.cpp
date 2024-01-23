#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex3;

void thread1()
{
    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 1 acquired lock1" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock3(mutex3);
    std::cout << "Thread 1 acquired lock3" << std::endl;
}

void thread2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate some work
    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 2 acquired lock1" << std::endl;
}

void thread3()
{
    std::unique_lock<std::mutex> lock1(mutex1);
    std::cout << "Thread 3 acquired lock1" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock3(mutex3);
    std::cout << "Thread 3 acquired lock3" << std::endl;
}

void thread4()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate some work
    std::unique_lock<std::mutex> lock3(mutex3);
    std::cout << "Thread 4 acquired lock3" << std::endl;
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

/*
both thread1 and thread3 lock mutex1 before attempting to lock mutex3, ensuring that they lock the mutexes in the same order and avoiding a potential deadlock. thread2 and thread4 still simulate some work to delay the acquisition of locks, but now the program will not enter a deadlock state.
*/