#include "Data.hpp"

Data::Data(int time) {

    this->time = time;

}

bool Data::operator<(Data& data) {

    return this->time < data.time;

}