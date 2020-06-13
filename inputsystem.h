#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H
#include <system.h>
#include <SDL2/SDL.h>
#include <vector>
#include "controller.h"
#include <memory>
#include "functionmanager.h"
class InputSystem : public System
{
private:
    SDL_Event& event;
    std::vector<std::shared_ptr<Controller>>controllers;
    FunctionManager &funcMan;
    EntityComponentManager &ecm;
public:
    InputSystem(SDL_Event& event, FunctionManager &funcMan, EntityComponentManager &ecm);

    // System interface
public:
    void think(EntityComponentManager &ecs, const std::unordered_set<Component::CID> &typedComponents, DataPack &dataPack) override;
};

#endif // INPUTSYSTEM_H
