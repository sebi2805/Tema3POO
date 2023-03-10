#ifndef BToyClass_J
#define BToyClass_J
#include <iostream>
#include <ostream>
#include <string.h>
#include "Clone.h"
#include "BPlay.h"
#include "Packing.h"
#include "AutoGeneratedIds.h"
using namespace std;
enum class ToyType
{
    Classic,
    Modern,
    Electronic,
    Educative
};
class BToyClass : virtual public Clone, public AutoGeneratedId, public BPlay
{
private:
    string name, category;
    float price, weight;
    int age;

protected:
    ToyType type;

public:
    explicit BToyClass(ToyType type, const string _name = "undefined", float _price = 0,
                       float _weight = 0, const string _category = "none", int _age = 3);
    BToyClass(const BToyClass &obj);
    BToyClass &operator=(const BToyClass &obj);
    virtual void print(ostream &out) const;
    virtual void read(istream &in);
    friend ostream &operator<<(ostream &out, const BToyClass &obj);
    friend istream &operator>>(istream &in, BToyClass &obj);
    bool operator==(const BToyClass &obj);
    bool operator!=(const BToyClass &obj);
    float getPrice();
    float getWeight();
    int getAge();
    ToyType getType();
    void playSound() override;
    Clone *clone() override;
    const string getName() const;
    const string getCategory() const;
    void setName(const string _name);
    void setCategory(const string category);
    void setPrice(float _price);
    void setWeight(float _weight);
    void setAge(float _age);
    void updateToy();
    virtual ~BToyClass()
    {
    }
};

#endif
