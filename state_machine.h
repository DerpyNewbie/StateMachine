#pragma once
#include "parameter.h"
#include "transition.h"

namespace state_machine
{
class StateMachine
{
    std::list<Parameter> m_parameters_ = {};
    std::list<Transition> m_any_state_transitions_ = {};
    State *m_entry_state_ = nullptr;
    State *m_current_state_ = nullptr;

public:
    explicit StateMachine(State *entry_state = nullptr, const std::list<Parameter> &parameters = {});

    void Tick(float delta_time);

    template <typename T>
    T ParameterValue(const std::string &name) const;

    void SetInt(const std::string &name, int value);
    void SetFloat(const std::string &name, float value);
    void SetBool(const std::string &name, bool value);

    template <typename T>
    void SetValue(const std::string &name, T value);
};

template <typename T>
T StateMachine::ParameterValue(const std::string &name) const
{
    for (auto &parameter : m_parameters_)
    {
        if (parameter.Name() != name)
        {
            continue;
        }

        return parameter.Value<T>();
    }

    return T{};
}

template <typename T>
void StateMachine::SetValue(const std::string &name, T value)
{
    for (auto &parameter : m_parameters_)
    {
        if (parameter.Name() != name)
        {
            continue;
        }

        parameter.Set(value);
        return;
    }

    m_parameters_.push_back({name, value});
}
}