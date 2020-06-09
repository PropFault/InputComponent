#include "inputmappingcomponent.h"
#include <string>
#include <iostream>
#include <init.h>
using namespace Components;

const std::string InputMappingComponent::INIT_PARAM_CONTROLLER_NUM = "controllerNum";
const std::string InputMappingComponent::INIT_PARAM_MAPPING = "mapping";
const std::string InputMappingComponent::INIT_PARAM_PACKAGED_COMPONENTS = "packagedComponents";


int InputMappingComponent::getControllerNum() const
{
    return controllerNum;
}

void InputMappingComponent::setControllerNum(int value)
{
    controllerNum = value;
}

std::unordered_map<InputAction, std::vector<std::string> > InputMappingComponent::getMapping() const
{
    return mapping;
}

void InputMappingComponent::setMapping(const std::unordered_map<InputAction, std::vector<std::string> > &value)
{
    mapping = value;
}

std::vector<Component::CID> InputMappingComponent::getPackagedComponents() const
{
    return packagedComponents;
}

void InputMappingComponent::setPackagedComponents(const std::vector<Component::CID> &value)
{
    packagedComponents = value;
}

InputMappingComponent::InputMappingComponent()
    :Component("InputMapping"), controllerNum(0)
{

}

void InputMappingComponent::_init(nlohmann::json json)
{
    int valid = 0;
    std::cout<<"initing the packagedComponents"<<std::endl;

    Init::initVector(json,INIT_PARAM_PACKAGED_COMPONENTS, this->packagedComponents);
    std::cout<<"inited the packagedComponents"<<std::endl;
    Init::init(json, INIT_PARAM_CONTROLLER_NUM, this->controllerNum, 1); // default to keyboard OR controller 1
    try{
        nlohmann::json mapJson = json.at(INIT_PARAM_MAPPING);
        for(auto row : mapJson){
            for(auto col = row.begin(); col != row.end(); ++col){
                InputAction action;
                action << col.key();
                Init::initVector(json, col.key(), this->mapping[action]);
            }
        }
        valid++;
    }catch(const nlohmann::detail::out_of_range &ex)
    {
        throw ex;
    }
    if(valid != 1)
        throw new std::runtime_error("NOT ALL REQUIRED PARAMETERS WERE INITIALISED!");

}

void InputMappingComponent::_deinit()
{
    this->mapping.clear();
    this->controllerNum = 0;
    this->packagedComponents.clear();
}

Component *InputMappingComponent::clone()
{
    return new InputMappingComponent(*this);
}
