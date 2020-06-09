#ifndef INPUTACTION_H
#define INPUTACTION_H
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
enum InputAction{
    STICK_L_X,
    STICK_L_Y,
    STICK_R_X,
    STICK_R_Y,
    DPAD_U,
    DPAD_D,
    DPAD_L,
    DPAD_R,
    ACTION_X,
    ACTION_Y,
    ACTION_A,
    ACTION_B,
    START,
    SELECT,
    SPECIAL,
    SHOULDER_L,
    SHOULDER_R,
    TRIGGER_L,
    TRIGGER_R
};


static InputAction operator<<(InputAction &target, const std::string &str){
    if(str == "STICK_L_X")
        target = STICK_L_X;
    else if(str == "STICK_L_Y")
        target = STICK_L_Y;
    else if(str == "STICK_R_X")
        target = STICK_R_X;
    else if(str == "STICK_R_Y")
        target = STICK_R_Y;
    else if(str == "DPAD_U")
        target = DPAD_U;
    else if(str == "DPAD_D")
        target = DPAD_D;
    else if(str == "DPAD_L")
        target = DPAD_L;
    else if(str == "DPAD_R")
        target = DPAD_R;
    else if(str == "ACTION_X")
        target = ACTION_X;
    else if(str == "ACTION_Y")
        target = ACTION_Y;
    else if(str == "ACTION_A")
        target = ACTION_A;
    else if(str == "ACTION_B")
        target = ACTION_B;
    else if(str == "START")
        target = START;
    else if(str == "SELECT")
        target = SELECT;
    else if(str == "SPECIAL")
        target = SPECIAL;
    else if(str == "SHOULDER_L")
        target = SHOULDER_L;
    else if(str == "SHOULDER_R")
        target = SHOULDER_R;
    else if(str == "TRIGGER_L")
        target = TRIGGER_L;
    else if(str == "TRIGGER_R")
        target = TRIGGER_R;
    return target;
}

/*if(str == "STICK_L_X")
    return STICK_L_X;
else if(str == "STICK_L_Y")
    return STICK_L_Y;
else if(str == "STICK_R_X")
    return STICK_R_X;
else if(str == "STICK_R_Y")
    return STICK_R_Y;
else if(str == "DPAD_U")
    return DPAD_U;
else if(str == "DPAD_D")
    return DPAD_D;
else if(str == "DPAD_L")
    return DPAD_L;
else if(str == "DPAD_R")
    return DPAD_R;*/

#endif // INPUTACTION_H
