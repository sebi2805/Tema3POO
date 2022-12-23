#ifndef TOY_FACTORY
#define TOY_FACTORY

#include "BToyClass.h"

class ToyFactory
{
public: // We want to be able to create toys from outside the class to create default toys
    BToyClass *createToy(const ToyType &type);
};

#endif