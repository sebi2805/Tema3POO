#ifndef CLONE_H
#define CLONE_H

class Clone
{
public:
    Clone(){};
    virtual Clone *clone() = 0;
    virtual ~Clone(){};
};
#endif