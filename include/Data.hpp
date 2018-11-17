#ifndef INCLUDED_DATA_HPP
#define INCLUDED_DATA_HPP

class Data {

private:
    int time;

public:
    Data(int);

    bool operator<(Data&);

};

#endif