#ifndef INPUTMAPPINGCOMPONENT_H
#define INPUTMAPPINGCOMPONENT_H

#include <unordered_map>
#include "inputaction.h"
#include <vector>
#include <string>
#include <component.h>

class InputMappingComponent : public Component
{
private:
    int controllerNum;
    std::unordered_map<InputAction, std::vector<std::string>> mapping;
    std::vector<Component::CID> packagedComponents;
public:
    static const std::string INIT_PARAM_CONTROLLER_NUM;
    static const std::string INIT_PARAM_MAPPING;
    static const std::string INIT_PARAM_PACKAGED_COMPONENTS;
    InputMappingComponent();

    // Component interface
protected:
    void _init(nlohmann::json json) override;
    void _deinit() override;

public:
    Component *clone() override;
    int getControllerNum() const;
    void setControllerNum(int value);
    std::unordered_map<InputAction, std::vector<std::string> > getMapping() const;
    void setMapping(const std::unordered_map<InputAction, std::vector<std::string> > &value);
    std::vector<Component::CID> getPackagedComponents() const;
    void setPackagedComponents(const std::vector<Component::CID> &value);
};

#endif // INPUTMAPPINGCOMPONENT_H
