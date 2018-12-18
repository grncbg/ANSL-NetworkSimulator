#include "Random.hpp"

#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

//
// class Random
//

template <class T>
Random<T>::Random() {

    boost::random::random_device seed_gen;
    this->engine = new boost::random::mt19937_64(seed_gen());

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

    this->poisson = new boost::random::poisson_distribution<int, double>(arg);

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

    this->exponential = new boost::random::exponential_distribution<double>(arg);

}

Exponential::~Exponential() {

    delete(this->exponential);

}

double Exponential::get() const {

    return (*exponential)(*engine);

}