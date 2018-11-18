#include "Random.hpp"

#include <random>

//
// class Random
//

template <class T>
Random<T>::Random() {

    std::random_device seed_gen;
    this->engine = new std::mt19937_64(seed_gen());

}

template <class T>
Random<T>::~Random() {

    delete(this->engine);

}

template <class T>
T Random<T>::operator()() const {

    return get();

}

//
// class Poison
//

Poisson::Poisson(double arg) {

    this->poisson = new std::poisson_distribution<int>(arg);

}

Poisson::~Poisson() {

    delete(this->poisson);

}

int Poisson::get() const {

    return (*poisson)(*engine);

}


//
// class Exponential
//

Exponential::Exponential(double arg) {

    this->exponential = new std::exponential_distribution<double>(arg);

}

Exponential::~Exponential() {

    delete(this->exponential);

}

double Exponential::get() const {

    return (*exponential)(*engine);

}