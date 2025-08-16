#pragma once

namespace state_machine
{
class StateMachine;

struct StateContext
{
    float delta_time;
    StateMachine *state_machine;
};
}