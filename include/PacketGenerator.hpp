#ifndef INCLUDED_PACKET_GENERATOR_HPP
#define INCLUDED_PACKET_GENERATOR_HPP

// dorward declaration
namespace std {

    // vector
    template <class T>
    class allocator;
    template <class T, class Allocator = allocator<T>>
    class vector;

}
// Data
class Data;
// Random
template <class T>
class Random;


//
// class PacketGenerator
//
class PacketGenerator {

public:

    static std::vector<Data>&& get(int);

};

#endif