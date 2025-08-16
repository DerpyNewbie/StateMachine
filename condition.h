#pragma once
#include "state_machine.h"

namespace state_machine
{
class StateMachine;

struct Condition
{
    virtual ~Condition() = default;
    virtual bool Evaluate(StateMachine *state_machine) const = 0;
};

struct TrueCondition final : Condition
{
    bool Evaluate(StateMachine *state_machine) const override;
};

struct FalseCondition final : Condition
{
    bool Evaluate(StateMachine *state_machine) const override;
};
}