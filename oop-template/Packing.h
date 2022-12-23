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
class BasicPacking
{
public:
    virtual ~BasicPacking() {}
    virtual void print(std::ostream &out) = 0;
};
class Box : public BasicPacking
{
    int height, width, length;
    std::string color;

    int height, width, length;
    std::string color;

public:
    Box(int height, int width, int length, std::string color) : height(height), width(width), length(length), color(color) {}
    void print(std::ostream &out);
    friend std::istream &operator>>(std::istream &in, Box &obj);
    friend std::ostream &operator<<(std::ostream &out, Box &obj);
    const std::string getColor() const;
    void operator=(const Box &obj);
    int getVolume() const;
    virtual ~Box() {}
};
class Bag : public BasicPacking
{

    std::string color;

public:
    Bag(std::string color) : color(color) {}
    void print(std::ostream &out);
    friend std::istream &operator>>(std::istream &in, Bag &obj);
    friend std::ostream &operator<<(std::ostream &out, Bag &obj);
    const std::string getColor() const;
    void operator=(const Bag &obj);
    virtual ~Bag() {}
};
#endif