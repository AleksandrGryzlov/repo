#include <iostream>
#include <thread>
#include "latch.h"

void test_count_down() {
    std::cout << "test_count_down" << std::endl;
    Latch latch(3);
    latch.count_down(1);
    latch.count_down(2);
    if (!latch.try_wait()) {
        std::cerr << "Error: Latch should have been opened" << std::endl;
        exit(1);
    }
    if (latch.try_wait()) {
        std::cerr << "Error: Latch should not have been opened" << std::endl;
        exit(1);
    }
}

void test_try_wait() {
    std::cout << "test_try_wait" << std::endl;
    Latch latch(2);
    if (latch.try_wait()) {
        std::cerr << "Error: Latch should not have been opened" << std::endl;
        exit(1);
    }
    latch.count_down(1);
    if (latch.try_wait()) {
        std::cerr << "Error: Latch should not have been opened" << std::endl;
        exit(1);
    }
    latch.count_down(1);
    if (!latch.try_wait()) {
        std::cerr << "Error: Latch should have been opened" << std::endl;
        exit(1);
    }
}

void test_wait() {
    std::cout << "test_wait" << std::endl;
    Latch latch(2);
    std::thread t([&latch]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    latch.count_down(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    latch.count_down(1);
        });
    latch.wait();
    t.join();
    std::cout << "Latch opened" << std::endl;
}

void test_arrive_and_wait() {
    std::cout << "test_arrive_and_wait" << std::endl;
    Latch latch(3);
    std::thread t1([&latch]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    latch.count_down(1);
        });
    std::thread t2([&latch]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    latch.count_down(2);
        });
    latch.arrive_and_wait();
    std::cout << "Latch opened" << std::endl;
    t1.join();
    t2.join();
}

int main() {
    test_count_down();
    test_try_wait();
    test_wait();
    test_arrive_and_wait();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
