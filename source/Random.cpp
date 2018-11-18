#include "Random.hpp"

#include <random>

Random::Random(const int poisson_arg = 0, const double exp_arg = 0.0) {

    std::random_device seed_gen;
    this->engine = new std::mt19937_64(seed_gen());
    this->poisson = new std::poisson_distribution<int>(poisson_arg);
    this->exponential = new std::exponential_distribution<double>(exp_arg);

}

Random::~Random() {

    delete(this->engine);
    delete(this->poisson);
    delete(this->exponential);

}
