#include "Random.hpp"

#include <random>

Random::Random() {

    std::random_device seed_gen;
    this->engine = new std::mt19937_64(seed_gen());

}

Random::~Random() {

    delete(this->engine);

}
