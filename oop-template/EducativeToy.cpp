#include <iostream>
#include <string>
#include "EducativeToy.h"
#include "BToyClass.h"

EducativeToy::EducativeToy(const std::string _name, float _price, float _weight,
                           const std::string _category, int _age, std::string abilityLearned) : BToyClass(ToyType::Educative, _name, _price, _weight, _category, _age),
                                                                                                abilityLearned(abilityLearned)
{
}
EducativeToy::EducativeToy(const EducativeToy &obj) : BToyClass(obj)
{
    abilityLearned = obj.abilityLearned;
}
const string EducativeToy::getAbilityLearned() const
{
    return abilityLearned;
};

void EducativeToy::setAbilityLearned(const string _abilityLearned)
{
    abilityLearned = _abilityLearned;
};
void EducativeToy::playSound()
{
    std::cout << "Hi! I'm " << getName() << " and I'm a educative toy." << endl;
};
bool EducativeToy::operator==(const EducativeToy &obj)
{
    return BToyClass::operator==(obj) && abilityLearned == obj.abilityLearned;
};
bool EducativeToy::operator!=(const EducativeToy &obj)
{
    return !(*this == obj);
};
EducativeToy &EducativeToy::operator=(const EducativeToy &obj)
{
    BToyClass::operator=(obj);
    abilityLearned = obj.abilityLearned;
    return *this;
};

void EducativeToy::print(ostream &out)
{
    out << *dynamic_cast<BToyClass *>(this);
    printSubClass(out);
}
ostream &operator<<(ostream &out, EducativeToy &obj)
{
    obj.BToyClass::print(out);
    obj.printSubClass(out);
    return out;
};
void EducativeToy::printSubClass(ostream &out)
{
    out << "        Abilitatea dezvoltata este: " << abilityLearned << endl;
};

istream &operator>>(istream &in, EducativeToy &obj)
{
    in >> *dynamic_cast<BToyClass *>(&obj);
    std::cout << "Introduceti abilitatea dezvoltata:" << endl;
    in.ignore();
    getline(in, obj.abilityLearned);
    return in;
};
Clone *EducativeToy::clone()
{
    return new EducativeToy(*this);
};