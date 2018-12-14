#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

#include "Data.hpp"
#include "PacketGenerator.hpp"
#include "Random.hpp"

using namespace std;

int main() {

    const unsigned int ARRIVAL_RATE_MAX = 100;
    const unsigned int ARRIVAL_RATE_MIN = 0;
    const unsigned int ARRIVAL_RATE_POINTS = 1001;

    unsigned int srcs[] = {1000, 10000};

    for(auto& src : srcs) {

        ofstream ofs("data/" + to_string(src) + ".csv");

        ofs << "arrival_rate, loss, throughput" << endl;



        ofs.close();

    }

}
