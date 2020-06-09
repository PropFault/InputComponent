#include "sdlcontroller.h"
#include <SDL2/SDL.h>
#include <exception>

int SDLController::getJoyId() const
{
    return joyId;
}

void SDLController::setJoyId(int value)
{
    joyId = value;
}

SDLController::SDLController(int joyId)
{
    SDL_Init(SDL_INIT_GAMECONTROLLER);
    int numMappings = SDL_GameControllerAddMappingsFromFile("./game/cfg/gamecontrollerdb.txt");
    if(numMappings == -1){
        throw new std::runtime_error("Failed loading controller mappings");
    }
    SDL_GameControllerEventState(SDL_IGNORE);
    this->joyId = joyId;
    this->controller  = SDL_GameControllerOpen(this->joyId);
}

SDLController::SDLController(const SDLController &other)
{
    this->controller = SDL_GameControllerOpen(other.joyId);
    this->joyId = other.joyId;
}

SDLController &SDLController::operator=(const SDLController &other)
{
    if(this == &other)
        return *this;
    SDL_GameControllerClose(this->controller);
    this->joyId = other.joyId;
    this->controller = SDL_GameControllerOpen(this->joyId);
    return *this;
}

SDLController::~SDLController()
{
    SDL_GameControllerClose(this->controller);
}



bool SDLController::getButton(InputAction action) const
{
    return this->getAxis(action) > 0.5f;
}

float SDLController::getAxis(InputAction action) const
{
    std::cout<<"CONTROLLER: " << this->controller << " ERR: " << SDL_GetError()<<std::endl;
    std::cout<<"GETTING AXIS FOR " << action <<std::endl;
    switch(action){
    case STICK_L_X:
        return SDL_GameControllerGetAxis(this->controller, SDL_CONTROLLER_AXIS_LEFTX);
    case STICK_L_Y:
        return SDL_GameControllerGetAxis(this->controller, SDL_CONTROLLER_AXIS_LEFTY);
    case STICK_R_X:
        return SDL_GameControllerGetAxis(this->controller, SDL_CONTROLLER_AXIS_RIGHTX);
    case STICK_R_Y:
        return SDL_GameControllerGetAxis(this->controller, SDL_CONTROLLER_AXIS_RIGHTY);
    case DPAD_U:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_DPAD_UP);
    case DPAD_D:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
    case DPAD_L:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
    case DPAD_R:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
    case ACTION_X:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_X);
    case ACTION_Y:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_Y);
    case ACTION_A:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_A);
    case ACTION_B:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_B);
    case START:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_START);
    case SELECT:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_BACK);
    case SPECIAL:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_GUIDE);
    case SHOULDER_L:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
    case SHOULDER_R:
        return SDL_GameControllerGetButton(this->controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
    case TRIGGER_L:
        return SDL_GameControllerGetAxis(this->controller, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
    case TRIGGER_R:
        return SDL_GameControllerGetAxis(this->controller, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
    }
}

bool SDLController::operator==(const int joyId) const
{
    return this->joyId == joyId;
}

bool SDLController::operator==(const SDLController &othr) const
{
    return this->joyId == othr.joyId;
}
