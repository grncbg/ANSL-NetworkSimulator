#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

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

    Poisson poisson(arrival_rate/srcs);
    PacketGenerator generator(1.0/duration);
    multiset<Data> set;

    for(unsigned int time = 0; time < END_TIME; time++) {

        packets += set.size();

        set.erase(Data(time));

        for(unsigned int src = 0; src < srcs; src++) {

            int num = poisson();
            calls += num;
            if( set.size() + num > MAX_PACKETS ) {
                lostCalls += set.size() + num - MAX_PACKETS;
                num = MAX_PACKETS - set.size();
            }
            for( auto &x : generator.get(num, time + 1) ) {

                set.insert(x);

            }

        }

    }

    Result result(arrival_rate, static_cast<double>(lostCalls)/static_cast<double>(calls), (packets * PACKET_WIDTH)/END_TIME);

    return move(result);

}

int main(int argc, char* argv[]) {

    const unsigned int ARRIVAL_RATE_MAX = 100;
    const unsigned int ARRIVAL_RATE_MIN = 0;
    const unsigned int ARRIVAL_RATE_POINTS = 1001;

    vector<unsigned int> srcs = {1000}; // default
    if(argc > 1) {

        srcs.resize(argc - 1);

        for(int i = 1; i < argc; i++)
            srcs[i - 1] = atoi(argv[i]);

    }

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
