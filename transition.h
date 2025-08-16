#pragma once
#include <list>

namespace state_machine
{
class StateMachine;
class State;
struct Condition;

struct Transition
{
    State *from;
    State *to;
    std::list<Condition *> conditions;

    bool Evaluate(StateMachine *state_machine);
};
}