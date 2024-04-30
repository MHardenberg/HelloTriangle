#include "gameClock.hpp"

void GameClock::idle() {
    auto start = this->now;
    this->mark();
    auto time = 
        std::chrono::duration_cast<std::chrono::milliseconds> 
        (this->now - start);

    std::this_thread::sleep_for(this->deltaTime - time);
}
