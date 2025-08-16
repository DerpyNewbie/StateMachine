#pragma once

#include "condition.h"
#include "state_context.h"

#include <list>
#include <string>

namespace state_machine
{
class ITransitionBuilder;
struct Transition;

class State
{
    friend class StateMachine;

    std::string m_name_;
    std::list<Transition> m_transitions_;
    bool m_looping_;

public:
    virtual ~State() = default;
    State() = default;

    virtual void OnEnter(const StateContext &ctx)
    {}

    /// <returns>`true` if the state should check for the next transition. `false` otherwise.</returns>
    virtual bool OnUpdate(const StateContext &ctx)
    {
        return true;
    }

    virtual void OnExit(const StateContext &ctx)
    {}

    [[nodiscard]] std::string Name() const;

    [[nodiscard]] bool IsLooping() const;

    /// <returns>this ptr</returns>
    [[maybe_unused]] State *SetLooping(bool should_loop);

    /// <returns>this ptr</returns>
    [[maybe_unused]] State *Then(ITransitionBuilder *builder);

    /// <returns>this ptr</returns>
    [[maybe_unused]] State *ToExit(const std::list<Condition *> &conditions = {});

    void RemoveTransitionTo(const std::string &next_state_name);
};
}