#ifndef INCLUDED_RANDOM_HPP
#define INCLUDED_RANDOM_HPP

// dorward declaration
namespace std {

    // mersenne_twister
    typedef __SIZE_TYPE__ size_t;
    typedef long unsigned int uint_fast64_t;

    template <class UIntType, size_t w, size_t n, size_t m, size_t r,
            UIntType a, size_t u, UIntType d, size_t s,
            UIntType b, size_t t,
            UIntType c, size_t l, UIntType f>
    class mersenne_twister_engine;

    using mt19937_64 = mersenne_twister_engine<
        uint_fast64_t,
        64, 312, 156, 31,
        0xb5026f5aa96619e9, 29, 0x5555555555555555,17,
        0x71d67fffeda60000, 37, 0xfff7eee000000000, 43, 6364136223846793005
    >;

    // poisson_distribution
    template <class IntType>
    class poisson_distribution;

}

class Random {

    std::mt19937_64* engine;
    std::poisson_distribution<int>* poisson;

};

#endif