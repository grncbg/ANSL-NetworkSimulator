#include "PacketGenerator.hpp"

#include <vector>

#include "Data.hpp"
#include "Random.hpp"

template <class T>
PacketGenerator<T>::PacketGenerator (int arg) {

    this->random = new T(arg);

}

template <class T>
PacketGenerator<T>::~PacketGenerator () {

    delete(this->random);

}

template <class T>
std::vector<Data>&& PacketGenerator<T>::get (int num) {

    std::vector<Data> data(num);
    for(auto &x : data) {
        x.set(this->random->get());
    }

    return std::move(data);

}