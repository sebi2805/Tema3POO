#ifndef CLASSIC_TOY
#define CLASSIC_TOY
#include "BToyClass.h"
#include "BPlay.h"
#include "Packing.h"
#include "Clone.h"
class ClassicToy : public BToyClass
{
    std::string material, color;
    Packing<Bag> packing{Bag("red")};

public:
    ClassicToy(const std::string _name = "undefined", float _price = 0, float _weight = 0,
               const std::string _category = "none", int _age = 3, int _id = 1,
               std::string material = "plastic", std::string color = "negru");
    ClassicToy(const ClassicToy &obj);
    const std::string getMaterial() const;
    const std::string getColor() const;
    void setMaterial(const string _material);
    void playSound() override;
    Clone *clone() override;
    void print(ostream &out) const override;
    void read(istream &in) override;
    void printSubClass(ostream &out) const;
    void setColor(const std::string _culoare);
    bool operator==(const ClassicToy &obj);
    bool operator!=(const ClassicToy &obj);
    friend ostream &operator<<(ostream &out, const ClassicToy &obj);
    friend istream &operator>>(istream &in, ClassicToy &obj);
    ClassicToy &operator=(const ClassicToy &obj);
};
#endif