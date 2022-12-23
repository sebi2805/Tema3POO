#include <iostream>
#include <string>
#include "ModernToy.h"
#include "ElectronicToy.h"
#include "EducativeToy.h"

ModernToy::ModernToy(const std::string _name, float _price, float _weight,
                     const std::string _category, int _age, std::string brand, int _numberBatteries,
                     std::string abilityLearned)
    : ElectronicToy(_name, _price, _weight, _category, _age, _numberBatteries),
      EducativeToy(_name, _price, _weight, _category, _age, abilityLearned), brand(brand), BToyClass(ToyType::Modern)
{
}
ModernToy::ModernToy(const ModernToy &obj) : ElectronicToy(obj), EducativeToy(obj), BToyClass(ToyType::Modern)
{
    brand = obj.brand;
}
const std::string ModernToy::getBrand() const
{
    return brand;
};

void ModernToy::setBrand(const std::string _brand)
{
    brand = _brand;
};

bool ModernToy::operator==(const ModernToy &obj)
{
    return ElectronicToy::operator==(obj) && EducativeToy::operator==(obj) && brand == obj.brand;
};
bool ModernToy::operator!=(const ModernToy &obj)
{
    return !(*this == obj);
};
ModernToy &ModernToy::operator=(const ModernToy &obj)
{
    ElectronicToy::operator=(obj);
    EducativeToy::operator=(obj);
    brand = obj.brand;
    return *this;
};
void ModernToy::playSound()
{
    std::cout << "Hi! I'm " << getName() << " and I'm a modern toy." << endl;
};
ostream &operator<<(ostream &out, ModernToy &obj)
{
    obj.BToyClass::print(out);
    obj.ElectronicToy::printSubClass(out);
    obj.EducativeToy::printSubClass(out);
    obj.printSubClass(out);
    return out;
};
istream &operator>>(istream &in, ModernToy &obj)
{

    in >> *dynamic_cast<ElectronicToy *>(&obj) >> *dynamic_cast<EducativeToy *>(&obj);
    std::cout << "Introduceti numele brandului:" << endl;
    in >> obj.brand;

    return in;
};
void ModernToy::printSubClass(ostream &out)
{
    out << "        Brandul este: " << brand << endl;
    packing.print(out);
}
void ModernToy::print(ostream &out)
{
    out << *this;
}
void playSound()
{
    cout << "Hi I'm Modern Toy" << endl;
}
Clone *ModernToy::clone()
{
    return new ModernToy(*this);
}
void ModernToy::read(istream &in)
{
    in >> *this;
}