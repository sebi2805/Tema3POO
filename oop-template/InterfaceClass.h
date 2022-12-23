#ifndef INTERFACE_CLASS
#define INTERFACE_CLASS
#include <iostream>
#include "Gift.h"
#include "GiftBuilder.h"
#include <memory>

class InterfaceMenu // Here we use the singletone design patter
{
private:
    std::vector<unique_ptr<Gift>> allGifts;
    int i;
    GiftBuilder giftBuilder;
    static InterfaceMenu *singleTone;

public:
    static void printMessage();
    InterfaceMenu(){

    };
    InterfaceMenu(InterfaceMenu &menu) = delete;
    InterfaceMenu &operator=(InterfaceMenu &obj) = delete;
    void start();
    ~InterfaceMenu()
    {
    }
    static InterfaceMenu *getInstance();
};
#endif