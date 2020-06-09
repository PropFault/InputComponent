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

InputEvent::InputEvent(InputAction action, bool buttonValue, float axisValue)
    :action(action), buttonValue(buttonValue), axisValue(axisValue)
{

}
