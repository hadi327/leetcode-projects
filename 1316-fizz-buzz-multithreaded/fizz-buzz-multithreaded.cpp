class FizzBuzz {
private:
    int n;
    int current;
    std::mutex mtx;
    std::condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->current = 1;
    }

    // printFizz() outputs "fizz"
    void fizz(std::function<void()> printFizz) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() {
                return current > n || (current % 3 == 0 && current % 5 != 0);
            });
            if (current > n) break;
            
            printFizz();
            current++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz"
    void buzz(std::function<void()> printBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() {
                return current > n || (current % 5 == 0 && current % 3 != 0);
            });
            if (current > n) break;
            
            printBuzz();
            current++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz"
    void fizzbuzz(std::function<void()> printFizzBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() {
                return current > n || (current % 15 == 0);
            });
            if (current > n) break;
            
            printFizzBuzz();
            current++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer
    void number(std::function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() {
                return current > n || (current % 3 != 0 && current % 5 != 0);
            });
            if (current > n) break;
            
            printNumber(current);
            current++;
            cv.notify_all();
        }
    }
};