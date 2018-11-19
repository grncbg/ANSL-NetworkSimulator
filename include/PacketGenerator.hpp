#ifndef INCLUDED_PACKET_GENERATOR_HPP
#define INCLUDED_PACKET_GENERATOR_HPP

#include <vector>

#include "Data.hpp"
#include "Random.hpp"
#include <iostream>


//
// class PacketGenerator
//
class PacketGenerator {

    Exponential* exp;

public:
    PacketGenerator(double arg) {

        this->exp = new Exponential(arg);

    }

    ~PacketGenerator() {

        delete(this->exp);

    }

    std::vector<Data> get(int num, int base) {

        std::vector<Data> data(num);
        for( auto &x : data ) {
            x.set(this->exp->get() + base);
        }

        return std::move(data);

    }

};

#endif