// Thread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

using namespace std::literals::chrono_literals;

static bool s_Finished = false;

void DoWork()
{
    std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;

    while (!s_Finished)
    {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }
}

void Thread()
{
    std::thread worker(DoWork);

    std::cin.get();
    // If we don't set the s_Finished to true, the worker will be in infinite while loop, which means
    // worker.join() will block the main thread forever
    s_Finished = true;

    // Blocks the current thread until the thread identified by *this finishes its execution. 
    worker.join();
    std::cout << "Finished.\n";
    std::cout << "Started thread id=" << std::this_thread::get_id();
}

struct Timer
{
    std::chrono::steady_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::steady_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::steady_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.f;
        std::cout << "Timer took" << ms << "ms" << std::endl;
    }
};

void TimingFunction()
{
    Timer timer;
    for (int i = 0; i < 100; i++)
        std::cout << "Hello\n";
}

void Timing()
{
    // The high_resolution_clock is not implemented consistently across different standard library implementations, and its use should be avoided
    // Generally one should just use std::chrono::steady_clock or std::chrono::system_clock directly instead of std::chrono::high_resolution_clock: 
    // use steady_clock for duration measurements, and system_clock for wall-clock time. 
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << " ms" << std::endl;
}

int main()
{
    //Thread();
    //Timing();
    TimingFunction();
}