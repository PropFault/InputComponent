#include "inputsystem.h"
#include "inputmappingcomponent.h"
#include "sdlcontroller.h"
#include "inputevent.h"


InputSystem::InputSystem(SDL_Event &event, FunctionManager &funcMan, EntityComponentManager &ecm)
    :System("InputMapping"),event(event), funcMan(funcMan), ecm(ecm)
{}

void InputSystem::think(EntityComponentManager &ecs, const std::unordered_set<Component::CID> &typedComponents, System::DataPack &dataPack)
{
    if(event.type == SDL_CONTROLLERDEVICEADDED){
        std::cout<<"ADDING " << event.cdevice.which<<std::endl;
        controllers.push_back(std::make_shared<SDLController>(event.cdevice.which));
        std::cout<<"ADDED"<<std::endl;
    }
    if(event.type == SDL_CONTROLLERDEVICEREMOVED){
        std::cout<<"REMOVING"<<std::endl;
        for(auto it = controllers.begin(); it != controllers.end();){
            if(*(std::static_pointer_cast<SDLController>(*it)) == event.cdevice.which){
                controllers.erase(it);
                std::cout<<"REMOVED"<<std::endl;
                break;
            }
            ++it;
        }
    }
    std::cout<<"LOOP START"<<std::endl;
    std::unordered_map<InputAction, std::pair<float, bool>> states;
    for(auto cid : typedComponents){
        std::cout<<"LOOKUP INPUT MAP "<<std::endl;
        InputMappingComponent *inputMapping = ecs.lookupCID<InputMappingComponent>(cid);
        std::cout<<"LOOKED UP INPUT MAP" <<std::endl;
        try {
            std::cout<<"1"<<std::endl;
            Controller& controller = *controllers.at(inputMapping->getControllerNum());

            std::cout<<"2"<<std::endl;
            for(auto it : inputMapping->getMapping()){

                std::cout<<"3"<<std::endl;
                if(states.find(it.first)==states.end()){

                    std::cout<<"4"<<std::endl;
                    states.insert(std::pair(it.first, std::pair(controller.getAxis(it.first), controller.getButton(it.first))));

                    std::cout<<"5"<<std::endl;
                }

                std::cout<<"6"<<std::endl;
                const auto& state = states.at(it.first);

                std::cout<<"7"<<std::endl;
                for(const auto& funcName : it.second){

                    std::cout<<"8"<<std::endl;
                    std::vector<Component*> packaged;
                    for(auto cid : inputMapping->getPackagedComponents()){
                        packaged.push_back(this->ecm.lookupCID<Component>(cid));
                    }

                    funcMan.call(funcName, InputEvent(it.first, state.second,state.first, packaged),cid);

                    std::cout<<"9"<<std::endl;
                }
            }
        }
        catch (const std::out_of_range &ex) {
            std::cout<<ex.what()<<std::endl;
        }

    }
}
