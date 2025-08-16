#include "delay_state.h"

void DelayState::OnEnter(const state_machine::StateContext &ctx)
{
    time_elapsed = 0.0f;
}

bool DelayState::OnUpdate(const state_machine::StateContext &ctx)
{
    return delay_in_seconds < time_elapsed;
}