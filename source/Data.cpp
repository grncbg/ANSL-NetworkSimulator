#include "Data.hpp"

Data::Data(int time) {

    this->time = time;

}

bool Data::operator<(const Data& data) const {

    return this->time < data.time;

}