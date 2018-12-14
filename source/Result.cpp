#include "Result.hpp"

#include <ostream>

std::ostream& operator << (std::ostream& os, const Result& r) {
    os << r.arrival_rate << ", " << r.loss << ", " << r.throughput;
    return os;
};