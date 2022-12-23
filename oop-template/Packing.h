#ifndef PACKING_H
#define PACKING_H

#include <iostream>
#include <ostream>
template <typename T> // Here we use the template
class Packing
{
    T type;

public:
    Packing(T _type) : type(_type)
    {
    }
    void print(std::ostream &out);

    virtual ~Packing()
    {
    }
};

class Box
{
    int height, width, length;

public:
    Box(int height, int width, int length) : height(height), width(width), length(length) {}
    void print(std::ostream &out);
    friend std::istream &operator>>(std::istream &in, Box &obj);
    friend std::ostream &operator<<(std::ostream &out, Box &obj);
    void operator=(const Box &obj);

    virtual ~Box()
    {
    }
};

#endif