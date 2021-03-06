#pragma once
#include "State.hpp"
#include <stack>

namespace Engine
{
    class StateMan {

    private:
        std::stack<std::unique_ptr<Engine::State>> m_stateStack;
        std::unique_ptr<Engine::State> m_state;

        bool m_remove = false;
        bool m_add = false;
        bool m_replace = false;

    public:
        StateMan();
        ~StateMan();

        void add(std::unique_ptr<Engine::State> toAdd, bool replace = false);
        void popCurrent();
        void popCount(int count);
        void processStateChange();
        std::unique_ptr<Engine::State> &getCurrent();
    };
};