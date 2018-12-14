#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

#include "Data.hpp"
#include "PacketGenerator.hpp"
#include "Random.hpp"
#include "Result.hpp"

using namespace std;

Result func(const unsigned int srcs, const double arrival_rate) {

    const unsigned int MAX_CAP = 100'000'000;
    const unsigned int PACKET_WIDTH = 64'000;
    const unsigned int MAX_PACKETS = MAX_CAP / PACKET_WIDTH;
    const unsigned int END_TIME = 1000;
    unsigned long long calls = 0;
    unsigned long long lostCalls = 0;
    unsigned long long packets = 0;
    const double duration = 180.0;

    return Result(0, 0, 0);

}

int main() {

    const unsigned int ARRIVAL_RATE_MAX = 100;
    const unsigned int ARRIVAL_RATE_MIN = 0;
    const unsigned int ARRIVAL_RATE_POINTS = 1001;

    unsigned int srcs[] = {1000, 10000};

    for(auto& src : srcs) {

        ofstream ofs("data/" + to_string(src) + ".csv");

        ofs << "arrival_rate, loss, throughput" << endl;

        for( unsigned int i = 0; i < ARRIVAL_RATE_POINTS; i++ ) {
            double arrival_rate = static_cast<double>(ARRIVAL_RATE_MAX - ARRIVAL_RATE_MIN) / static_cast<double>(ARRIVAL_RATE_POINTS) * (i + 1);

            auto tmp =  func(src, arrival_rate);

            ofs << tmp << "\n";
        }

        ofs.close();

    }

}
