#include "Packing.h"
#include <ostream>
#include <iostream>
template <typename T>
void Packing<T>::print(std::ostream &out) const
{
    out << "The packing is: " << type << std::endl;
};
template <>
void Packing<Box>::print(std::ostream &out) const
{
    out << "The packing is: box and the volume of the box is " << type.getVolume() << std::endl;
};
template <>
void printTemplate(Box &obj)
{
    std::cout << "The box is: " << obj.getVolume() << std::endl;
};
template <>
void Packing<Bag>::print(std::ostream &out) const
{
    type.print(out);
};
void Box::print(std::ostream &out) const
{
    out << "The box is: " << height << "x" << width << "x" << length << std::endl;
}

void Box::operator=(const Box &obj)
{
    height = obj.height;
    width = obj.width;
    length = obj.length;
}
std::istream &operator>>(std::istream &in, Box &obj)
{
    in >> obj.height >> obj.width >> obj.length;
    return in;
}
int Box::getVolume() const
{
    return height * width * length;
}
std::ostream &operator<<(std::ostream &out, Box &obj)
{
    obj.print(out);
    return out;
}
const std::string Box::getColor() const
{
    return color;
}
// void Bag::print(std::ostream &out) const
// {
//     out << "The bag is: " << color << std::endl;
// }
void Bag::print(std::ostream &out) const
{
    out << "The bag is: " << color << std::endl;
}
std::istream &operator>>(std::istream &in, Bag &obj)
{
    in >> obj.color;
    return in;
}
std::ostream &operator<<(std::ostream &out, Bag &obj)
{
    obj.print(out);
    return out;
}
const std::string Bag::getColor() const
{
    return color;
}
void Bag::operator=(const Bag &obj)
{
    color = obj.color;
}
