#pragma once
#include "delay_state.h"
#include "set_parameter_state.h"
#include "../transition_builder.h"
#include "../parameter_conditions.h"
#include "../state.h"

namespace state_machine
{
class Demo
{
public:
    void Create()
    {

        const auto entry_point = (new State());

        entry_point->Then((new TransitionBuilder<DelayState>())
                          ->When<NotEqual<bool>>("Entered", true)
                          ->Then(new TransitionBuilder<SetParameterState<bool>>("Entered", true)))
                   ->Then(new TransitionBuilder{new DelayState});

        new StateMachine(entry_point);
    }
};
}