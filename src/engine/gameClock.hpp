#pragma once
#include <chrono>
#include <thread>


class GameClock {
    public:
        constexpr static long dtMilli = (long)(1000./ 60);
    private:
        std::chrono::milliseconds deltaTime = 
            std::chrono::milliseconds(this->dtMilli);
        std::chrono::time_point<std::chrono::high_resolution_clock> now;

    public:
        void mark() {
            now = std::chrono::high_resolution_clock::now();
        }

        void idle();
};
