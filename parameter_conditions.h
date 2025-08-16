#pragma once
#include "condition.h"
#include "state_machine.h"

namespace state_machine
{
template <typename T>
struct ComparisonCondition : Condition
{
    std::string parameter_name;
    T comparing_value;

    ComparisonCondition(std::string parameter_name, T comparing_value) :
        parameter_name(std::move(parameter_name)),
        comparing_value(comparing_value)
    {}

    T ReferenceValue(const StateMachine *state_machine) const
    {
        return state_machine->ParameterValue<T>(parameter_name);
    }
};

template <typename T>
struct Equal final : ComparisonCondition<T>
{
    Equal(const std::string &parameter_name, T comparing_value) :
        ComparisonCondition<T>(parameter_name, comparing_value)
    {}

    bool Evaluate(StateMachine *state_machine) const override
    {
        return ComparisonCondition<T>::ReferenceValue(state_machine) == ComparisonCondition<T>::comparing_value;
    }
};

template <typename T>
struct NotEqual final : ComparisonCondition<T>
{
    NotEqual(const std::string &parameter_name, T comparing_value) :
        ComparisonCondition<T>(parameter_name, comparing_value)
    {}

    bool Evaluate(StateMachine *state_machine) const override
    {
        return ComparisonCondition<T>::ReferenceValue(state_machine) != ComparisonCondition<T>::comparing_value;
    }
};

template <typename T>
struct GreaterThan final : ComparisonCondition<T>
{
    GreaterThan(const std::string &parameter_name, T comparing_value) :
        ComparisonCondition<T>(parameter_name, comparing_value)
    {}

    bool Evaluate(StateMachine *state_machine) const override
    {
        return ComparisonCondition<T>::ReferenceValue(state_machine) > ComparisonCondition<T>::comparing_value;
    }
};

template <typename T>
struct LessThan final : ComparisonCondition<T>
{
    LessThan(const std::string &parameter_name, T comparing_value) :
        ComparisonCondition<T>(parameter_name, comparing_value)
    {}

    bool Evaluate(StateMachine *state_machine) const override
    {
        return ComparisonCondition<T>::ReferenceValue(state_machine) < ComparisonCondition<T>::comparing_value;
    }
};
}