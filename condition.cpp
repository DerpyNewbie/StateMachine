#include "condition.h"

namespace state_machine
{
bool TrueCondition::Evaluate(StateMachine *state_machine) const
{
    return true;
}
bool FalseCondition::Evaluate(StateMachine *state_machine) const
{
    return false;
}
}