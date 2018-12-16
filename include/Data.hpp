#ifndef INCLUDED_DATA_HPP
#define INCLUDED_DATA_HPP

class Data {

private:
    unsigned int end_time;

public:
    Data() = default;
    Data(unsigned int);
    void set(unsigned int);
    unsigned int get(){return end_time;};

    bool operator<(const Data&) const;
    bool operator==(const Data& data) const { return this->end_time == data.end_time ;};

};

#endif