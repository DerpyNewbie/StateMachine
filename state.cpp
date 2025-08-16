#include "state.h"
#include "condition.h"
#include "transition_builder.h"

namespace state_machine
{
std::string State::Name() const
{
    return m_name_;
}

bool State::IsLooping() const
{
    return m_looping_;
}

State *State::SetLooping(const bool should_loop)
{
    m_looping_ = should_loop;
    return this;
}

State *State::Then(ITransitionBuilder *builder)
{
    m_transitions_.emplace_back(this, builder->m_state_, builder->m_conditions_);
    return this;
}

State *State::ToExit(const std::list<Condition *> &conditions)
{
    m_transitions_.emplace_back(this, nullptr, conditions);
    return this;
}

void State::RemoveTransitionTo(const std::string &next_state_name)
{
    std::erase_if(m_transitions_, [next_state_name](const auto &t) {
        return t.to->Name() == next_state_name;
    });
}
}