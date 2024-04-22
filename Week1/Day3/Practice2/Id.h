#ifndef ID_H
#define ID_H
#include <iostream>
#include "Enums.h"
class Id
{
private:
    /* data */
    Country _country{Country::IN};
    int _year{24};
    int _month{01};
    TrackLevel _trackLevel{TrackLevel::BASIC};
    int _batchNumber{01};
    Track _trackName{Track::C};
    

public:
    Id() {}
    ~Id() {}
};

#endif // ID_H
