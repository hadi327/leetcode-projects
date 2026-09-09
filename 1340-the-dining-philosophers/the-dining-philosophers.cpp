class DiningPhilosophers {
private:
    std::mutex forks[5];

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void()> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        // Always lock the lower-indexed fork first to prevent circular wait/deadlocks
        std::unique_lock<std::mutex> lck1(forks[std::min(left, right)]);
        std::unique_lock<std::mutex> lck2(forks[std::max(left, right)]);

        pickLeftFork();
        pickRightFork();
        
        eat();
        
        putRightFork();
        putLeftFork();
    }
};