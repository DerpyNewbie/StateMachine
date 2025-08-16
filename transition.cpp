#include "transition.h"
#include "condition.h"
#include <algorithm>

namespace state_machine
{
bool Transition::Evaluate(StateMachine *state_machine)
{
    return conditions.empty() ||
           std::ranges::all_of(conditions, [state_machine](const auto &condition) {
               return condition->Evaluate(state_machine);
           });
}
}