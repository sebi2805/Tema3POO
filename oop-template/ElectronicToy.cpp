#include <iostream>
#include <string>
#include "ElectronicToy.h"
#include "BToyClass.h"
using namespace std;
ElectronicToy::ElectronicToy(const std::string _name, float _price, float _weight,
                             const std::string _category, int _age, int numberBatteries) : BToyClass(ToyType::Electronic, _name, _price, _weight, _category, _age),
                                                                                           numberBaterries(numberBaterries)
{
}
ElectronicToy::ElectronicToy(const ElectronicToy &obj) : BToyClass(obj)
{
    numberBaterries = obj.numberBaterries;
}
const int ElectronicToy::getNumberBatteries() const
{
    return numberBaterries;
    ;
};

void ElectronicToy::setNumberBatteries(const int _numberBatteries)
{
    numberBaterries = _numberBatteries;
};

bool ElectronicToy::operator==(const ElectronicToy &obj)
{
    return BToyClass::operator==(obj) && numberBaterries == obj.numberBaterries;
};
bool ElectronicToy::operator!=(const ElectronicToy &obj)
{
    return !(*this == obj);
};
ElectronicToy &ElectronicToy::operator=(const ElectronicToy &obj)
{
    BToyClass::operator=(obj);
    numberBaterries = obj.numberBaterries;
    return *this;
};
void ElectronicToy::playSound()
{
    std::cout << "Hi! I'm " << getName() << " and I'm a electronic toy." << endl;
};
void ElectronicToy::print(ostream &out)
{
    BToyClass::print(out);
    print(out);
};
ostream &operator<<(ostream &out, ElectronicToy &obj)
{

    obj.BToyClass::print(out);
    obj.print(out);
    return out;
};
void ElectronicToy::printSubClass(ostream &out)
{
    out << "        Numarul de baterii este: " << numberBaterries << endl;
};
istream &operator>>(istream &in, ElectronicToy &obj)
{
    in >> *dynamic_cast<BToyClass *>(&obj);
    std::cout << "Introduceti numarul de baterii:" << endl;
    in >> obj.numberBaterries;

    return in;
};
Clone *ElectronicToy::clone()
{
    return new ElectronicToy(*this);
}