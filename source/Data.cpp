#include "Data.hpp"

Data::Data(unsigned int time) {

    this->end_time = time;

}

void Data::set(unsigned int time) {

    this->end_time = time;

}

bool Data::operator<(const Data& data) const {

    return this->end_time < data.end_time;

}