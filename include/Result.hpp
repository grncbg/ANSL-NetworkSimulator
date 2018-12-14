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
    class ostream;
}

std::ostream& operator << (std::ostream& os, const Result& r) {
    os << r.arrival_rate << ", " << r.loss << ", " << r.throughput;
    return os;
};

#endif