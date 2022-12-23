#include "ToyFactory.h"
#include "ClassicToy.h"
#include "EducativeToy.h"
#include "ElectronicToy.h"
#include "ModernToy.h"

BToyClass *ToyFactory::createToy(const ToyType &type)
{
    switch (type)
    {
    case ToyType::Classic:
        return new ClassicToy();
    case ToyType::Educative:
        return new EducativeToy();
    case ToyType::Electronic:
        return new ElectronicToy();
    case ToyType::Modern:
        return new ModernToy();
    default:
        return nullptr;
    }
}