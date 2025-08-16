#pragma once
#include "state.h"

namespace state_machine
{
class ITransitionBuilder
{
protected:
    friend class State;
    State *m_state_;
    std::list<Condition *> m_conditions_;

    ITransitionBuilder(State *state, const std::list<Condition *> &conditions) :
        m_state_(state), m_conditions_(conditions)
    {}

public:
    // ReSharper disable once CppNonExplicitConvertingConstructor
    ITransitionBuilder(State *state) : m_state_(state)
    {}

    template <typename Condition, typename... Args>
    ITransitionBuilder *AddCondition(Args... args)
    {
        m_conditions_.emplace_back(new Condition(args...));
        return this;
    }
};

template <typename State>
class TransitionBuilder : public ITransitionBuilder
{
public:
    // ReSharper disable once CppNonExplicitConvertingConstructor
    TransitionBuilder(State *state) : ITransitionBuilder(state)
    {}

    // ReSharper disable once CppNonExplicitConvertingConstructor
    template <typename... Args>
    TransitionBuilder(Args... args) : ITransitionBuilder(new State(args...))
    {}

    template <typename Condition, typename... Args>
    TransitionBuilder *When(Args... args)
    {
        m_conditions_.emplace_back(new Condition(args...));
        return this;
    }

    TransitionBuilder *Then(ITransitionBuilder *builder)
    {
        m_state_->Then(builder);

        return this;
    }
};
}