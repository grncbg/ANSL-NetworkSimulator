#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>

#include "CommandLineOption.hpp"
#include "Data.hpp"
#include "PacketGenerator.hpp"
#include "Random.hpp"
#include "Result.hpp"

using namespace std;

Result func(const unsigned int srcs, const double arrival_rate) {

    constexpr unsigned int MAX_CAP = 100'000'000;
    constexpr unsigned int PACKET_WIDTH = 64'000;
    constexpr unsigned int MAX_PACKETS = MAX_CAP / PACKET_WIDTH;
    constexpr unsigned int START_TIME = 1000;
    constexpr unsigned int END_TIME = 2000;
    unsigned long long calls = 0;
    unsigned long long lostCalls = 0;
    unsigned long long packets = 0;
    constexpr double duration = 180.0;

    unique_ptr<Data> data[srcs] = {0};

    Poisson poisson(arrival_rate/srcs);
    PacketGenerator generator(1.0/duration);
    multiset<Data> set;

    for(unsigned int time = 0; time < END_TIME; time++) {

        if (time >= START_TIME)
            packets += set.size();

        set.erase(Data(time));

        for(unsigned int src = 0; src < srcs; src++) {

            if( data[src] != nullptr ) {
                if(data[src]->get() > time)
                    continue;
                data[src].reset(nullptr);
            }

            if(poisson() < 1)
                continue;

            if (time >= START_TIME)
                calls++;

            if( set.size() + 1 > MAX_PACKETS ) {
                if (time >= START_TIME)
                    lostCalls++;
                continue;
            }

            data[src] = generator.get(time + 1);
            set.insert(*(data[src]));

        }

    }

    Result result(arrival_rate, static_cast<double>(lostCalls)/static_cast<double>(calls), (packets * PACKET_WIDTH)/(END_TIME-START_TIME));

    return move(result);

}

int main(int argc, char* argv[]) {

    constexpr unsigned int ARRIVAL_RATE_MAX = 30;
    constexpr unsigned int ARRIVAL_RATE_MIN = 0;
    constexpr unsigned int ARRIVAL_RATE_POINTS = 1001;

    CommandLineOption<unsigned int> options(argc, argv);
    const unique_ptr<vector<unsigned int>> srcs = options.parse().move();
    if(srcs == nullptr) {
        cerr << "Require arguments" << endl;
        return 0;
    }

    vector<Result> result(ARRIVAL_RATE_POINTS);

    for(auto& src : (*srcs)) {

        ofstream ofs("data/" + to_string(src) + ".csv");

        ofs << "arrival_rate, loss, throughput" << endl;

        #pragma omp parallel for schedule(guided)
        for( unsigned int i = 0; i < ARRIVAL_RATE_POINTS; i++ ) {
            double arrival_rate = static_cast<double>(ARRIVAL_RATE_MAX - ARRIVAL_RATE_MIN) / static_cast<double>(ARRIVAL_RATE_POINTS) * (i + 1);

            result[i] =  func(src, arrival_rate);

        }

        for(auto& x : result)
            ofs << x << endl;

        ofs.close();

    }

}
