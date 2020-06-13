#include "inputevent.h"

float InputEvent::getAxisValue() const
{
    return axisValue;
}

void InputEvent::setAxisValue(float value)
{
    axisValue = value;
}

bool InputEvent::getButtonValue() const
{
    return buttonValue;
}

void InputEvent::setButtonValue(bool value)
{
    buttonValue = value;
}

InputAction InputEvent::getAction() const
{
    return action;
}

void InputEvent::setAction(const InputAction &value)
{
    action = value;
}

std::vector<Component *> InputEvent::getPackagedComponents() const
{
    return packagedComponents;
}

void InputEvent::setPackagedComponents(const std::vector<Component *> &value)
{
    packagedComponents = value;
}

InputEvent::InputEvent(InputAction action, bool buttonValue, float axisValue, const std::vector<Component*> components)
    :action(action), buttonValue(buttonValue), axisValue(axisValue),packagedComponents(components)
{

}
