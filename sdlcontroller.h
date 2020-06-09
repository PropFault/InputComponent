#ifndef SDLCONTROLLER_H
#define SDLCONTROLLER_H
#include "controller.h"
#include <SDL2/SDL.h>
#include "inputaction.h"

class SDLController : public Controller
{
private:
    int joyId;
    SDL_GameController *controller;
public:
    SDLController(int joyId);
    SDLController(const SDLController& other);
    SDLController& operator=(const SDLController& other);
    ~SDLController();
    // Controller interface
public:
    bool getButton(InputAction action) const override;
    float getAxis(InputAction action) const override;
    bool operator==(const int joyId)const;
    bool operator==(const SDLController& othr)const;
    int getJoyId() const;
    void setJoyId(int value);
};

#endif // SDLCONTROLLER_H
