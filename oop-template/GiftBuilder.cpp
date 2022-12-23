#include "GiftBuilder.h"
#include "ToyFactory.h"
#include "Packing.h"
#include "Gift.h"

GiftBuilder::GiftBuilder()
{
    reset();
}
void GiftBuilder::reset()
{
    gift = Gift();
}
Gift GiftBuilder::build()
{
    Gift temp = gift;
    reset();
    return temp;
}
GiftBuilder &GiftBuilder::setName(const string _name)
{
    gift.setName(_name);
    return *this;
}
GiftBuilder &GiftBuilder::setDestination(const string _destination)
{
    gift.setDestination(_destination);
    return *this;
}
GiftBuilder &GiftBuilder::setPersonName(const string _personName)
{
    gift.setPersonName(_personName);
    return *this;
}
GiftBuilder &GiftBuilder::setToys(const vector<shared_ptr<BToyClass>> _toys, const int _toysLength)
{
    gift.setToys(_toys, _toysLength);
    return *this;
}

Gift &GiftBuilder::getGift()
{
    return gift;
}
