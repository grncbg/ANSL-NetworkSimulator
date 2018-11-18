#include "Random.hpp"

#include <random>

//
// class Random
//

Random::Random() {

    std::random_device seed_gen;
    this->engine = new std::mt19937_64(seed_gen());

}

Random::~Random() {

    delete(this->engine);

}


//
// class Poison
//

Poisson::Poisson(int arg) {

    this->poisson = new std::poisson_distribution<int>(arg);

}

Poisson::~Poisson() {

    delete(this->poisson);

}