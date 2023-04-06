#include <mutex>
#include <condition_variable>

class latch {
public:
    explicit latch(size_t count) : count_(count) {}

    void count_down(unsigned int amtToDecrement = 1) {
        std::lock_guard<std::mutex> lock(mutex_);
        count_ -= amtToDecrement;
        if (count_ == 0) {
            cv_.notify_all();
        }
    }

    bool try_wait() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return count_ == 0;
    }

    void wait() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return count_ == 0; });
    }

    void arrive_and_wait() {
        count_down();
        wait();
    }

private:
    mutable std::mutex mutex_;
    std::condition_variable cv_;
    size_t count_;
};