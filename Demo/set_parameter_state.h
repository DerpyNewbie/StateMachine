#pragma once
#include "../state.h"

template <typename T>
class SetParameterState : public state_machine::State
{
public:
    SetParameterState(const std::string &name, T value) : name(name), value(value)
    {}

    std::string name;
    T value;

    void OnEnter(const state_machine::StateContext &ctx) override;
};

template <typename T>
void SetParameterState<T>::OnEnter(const state_machine::StateContext &ctx)
{
    ctx.state_machine->SetValue(name, value);
}