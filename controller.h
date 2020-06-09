#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "inputaction.h"

class Controller
{
public:
    virtual bool getButton(InputAction action)const = 0;
    virtual float getAxis(InputAction action)const = 0;
    virtual ~Controller(){};

};

#endif // CONTROLLER_H
