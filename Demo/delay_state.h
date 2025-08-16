#pragma once
#include "../state.h"

class DelayState : public engine::state_machine::State
{
public:
    float delay_in_seconds = 1.0f;
    float time_elapsed = 0.0f;

    void OnEnter(const engine::state_machine::StateContext &ctx) override;
    bool OnUpdate(const engine::state_machine::StateContext &ctx) override;
};