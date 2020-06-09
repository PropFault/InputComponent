#ifndef INPUTEVENT_H
#define INPUTEVENT_H
#include "inputaction.h"

class InputEvent
{
private:
    float axisValue;
    bool buttonValue;
    InputAction action;
public:
    InputEvent(InputAction action, bool buttonValue, float axisValue);
    float getAxisValue() const;
    void setAxisValue(float value);
    bool getButtonValue() const;
    void setButtonValue(bool value);
    InputAction getAction() const;
    void setAction(const InputAction &value);
};

#endif // INPUTEVENT_H
