#include "Packing.h"
#include <ostream>
#include <iostream>
template <typename T>
void Packing<T>::print(std::ostream &out)
{
    out << "The packing is: " << type << std::endl;
};
void Box::print(std::ostream &out)
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
std::ostream &operator<<(std::ostream &out, Box &obj)
{
    obj.print(out);
    return out;
}