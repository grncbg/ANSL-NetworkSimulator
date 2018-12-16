#ifndef INCLUDED_PACKET_GENERATOR_HPP
#define INCLUDED_PACKET_GENERATOR_HPP

#include <vector>

#include "Data.hpp"
#include "Random.hpp"
#include <iostream>
#include <memory>


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

    std::unique_ptr<Data> get(int base) {

        std::unique_ptr<Data> data(new Data);
        data->set(this->exp->get() + base);

        return std::move(data);

    }

};

#endif