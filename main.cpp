#include <stdio.h>
#include <componentplugin.h>
#include "inputmappingcomponent.h"
#include "inputsystem.h"
namespace plugins {
class InputComponentPlugin : public ComponentPlugin{
private:
    // ComponentPlugin interface
public:
    void onRegisterComponents(const Context &context){
        std::cout<<"onRegisterComponent"<<std::endl;
        EntityComponentManager &ecm = context.getEcm();
        ecm.registerBlueprint(new InputMappingComponent());
    }
    void onRegisterSystems(SystemPipeline &pipeline, const Context &context){
        pipeline.add(new InputSystem(context.event, context.getFuncMan()));
    }
};
extern "C" BOOST_SYMBOL_EXPORT InputComponentPlugin plugin;
InputComponentPlugin plugin;
}
