#include "state_machine.h"
#include "state.h"
#include "state_context.h"

namespace state_machine
{
StateMachine::StateMachine(State *entry_state, const std::list<Parameter> &parameters)
{
    m_parameters_ = parameters;
    m_entry_state_ = entry_state;
    m_current_state_ = entry_state;
}

void StateMachine::Tick(const float delta_time)
{
    const StateContext ctx{delta_time, this};

    if (m_current_state_ == nullptr)
    {
        m_current_state_ = m_entry_state_;
        m_current_state_->OnEnter(ctx);
    }

    if (!m_current_state_->OnUpdate(ctx))
    {
        return;
    }

    // exiting
    if (!m_current_state_->IsLooping() && m_current_state_->m_transitions_.empty())
    {
        m_current_state_->OnExit(ctx);
        m_current_state_ = nullptr;
        return;
    }

    for (auto transition : m_current_state_->m_transitions_)
    {
        if (!transition.Evaluate(this))
        {
            continue;
        }

        // transitioning
        m_current_state_->OnExit(ctx);
        m_current_state_ = transition.to;
        if (m_current_state_ != nullptr)
        {
            m_current_state_->OnEnter(ctx);
        }

        break;
    }
}

void StateMachine::SetInt(const std::string &name, const int value)
{
    for (auto &parameter : m_parameters_)
    {
        if (parameter.Name() != name)
        {
            continue;
        }

        parameter.SetInt(value);
    }
}

void StateMachine::SetFloat(const std::string &name, const float value)
{
    for (auto &parameter : m_parameters_)
    {
        if (parameter.Name() != name)
        {
            continue;
        }

        parameter.SetFloat(value);
    }
}

void StateMachine::SetBool(const std::string &name, const bool value)
{
    for (auto &parameter : m_parameters_)
    {
        if (parameter.Name() != name)
        {
            continue;
        }

        parameter.SetBool(value);
    }
}
}