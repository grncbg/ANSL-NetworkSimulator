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