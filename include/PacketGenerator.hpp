#ifndef INCLUDED_PACKET_GENERATOR_HPP
#define INCLUDED_PACKET_GENERATOR_HPP

#define VECTOR_FWD(x_type)  std::vector<x_type, std::allocator<x_type> >

// dorward declaration
namespace std {

    // vector
    template <class T>
    class allocator;
    template <class T, class Allocator>
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
template <class T>
class PacketGenerator {

    Random<T>* random;

public:
    PacketGenerator(int);
    ~PacketGenerator();

    VECTOR_FWD(Data)&& get(int);

};

#endif