#ifndef INPUTEVENT_H
#define INPUTEVENT_H
#include "inputaction.h"
#include <vector>
#include "../BlastCompany/component.h"
class InputEvent
{
private:
    float axisValue;
    bool buttonValue;
    InputAction action;
    std::vector<Component*> packagedComponents;
public:
    InputEvent(InputAction action, bool buttonValue, float axisValue, const std::vector<Component*> components);
    float getAxisValue() const;
    void setAxisValue(float value);
    bool getButtonValue() const;
    void setButtonValue(bool value);
    InputAction getAction() const;
    void setAction(const InputAction &value);
    std::vector<Component *> getPackagedComponents() const;
    void setPackagedComponents(const std::vector<Component *> &value);
};

#endif // INPUTEVENT_H
