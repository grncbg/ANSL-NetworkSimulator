#ifndef INCLUDED_RESULT_HPP
#define INCLUDED_RESULT_HPP

struct Result {

    double arrival_rate;
    double loss;
    unsigned int throughput;

    Result(double arrival_rate, double loss, unsigned int throughput) {
        this->arrival_rate = arrival_rate;
        this->loss = loss;
        this->throughput = throughput;
    }

};

namespace std{
    template<class charT> struct char_traits;
    template<class CharT, class Traits>
    class basic_ostream;
    typedef class basic_ostream<char, char_traits<char>> ostream;
}

std::ostream& operator << (std::ostream&, const Result&);

#endif