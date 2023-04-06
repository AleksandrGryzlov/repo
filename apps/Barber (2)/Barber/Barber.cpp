#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int main() {
    mutex barberReady;
    mutex waitChairsCanBeAccessed;
    condition_variable readyCustomers;
    int numWaitChairs = 10;
    int numReadyCustomers = 0;
    bool done = false;
    thread t1([&]() {
        while (true) {
            unique_lock<mutex> lk(waitChairsCanBeAccessed);
            readyCustomers.wait(lk, [&]() { return numReadyCustomers > 0 || done; });
            if (done && numReadyCustomers == 0) {
                break;
            }
            numReadyCustomers--;
            lk.unlock();
            barberReady.lock();
            cout << "Barber cutting hair\n";
            barberReady.unlock();
        }
        });
    thread t2([&]() {
        while (true) {
            unique_lock<mutex> lk(waitChairsCanBeAccessed);
            if (numReadyCustomers < numWaitChairs) {
                numReadyCustomers++;
                cout << "Customer enters the barbershop and sits in the waiting room" << endl;
                readyCustomers.notify_one();
            }
            else {
                cout << "Customer leaves the barbershop because barbershop is full" << endl;
            }
        }
    { unique_lock<mutex> lk(waitChairsCanBeAccessed); done = true; }
    readyCustomers.notify_one();
        });
    t1.join();
    t2.join();
    return 0;
}