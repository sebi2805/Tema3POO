#ifndef GIFT_BUILDER
#define GIFT_BUILDER

#include "Gift.h"

class GiftBuilder
{
private:
    Gift gift;

public:
    GiftBuilder();
    void reset();
    Gift build();
    GiftBuilder &setName(const string _name);
    GiftBuilder &setDestination(const string _destination);
    GiftBuilder &setPersonName(const string _personName);
    GiftBuilder &setToys(const vector<shared_ptr<BToyClass>> _toys, const int _toysLength);
    Gift &getGift();
};
#endif