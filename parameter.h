#pragma once
#include <cassert>
#include <cstdint>
#include <string>

namespace state_machine
{
enum class kParameterType : std::uint8_t
{
    kInt,
    kFloat,
    kBool
};

class Parameter
{
    std::string m_name_;
    union ParameterValue
    {
        int m_int_;
        float m_float_;
        bool m_bool_;
    };
    ParameterValue m_value_;
    kParameterType m_type_;

public:
    // ReSharper disable once CppNonExplicitConvertingConstructor
    Parameter(std::string name, int value);

    // ReSharper disable once CppNonExplicitConvertingConstructor
    Parameter(std::string name, float value);

    // ReSharper disable once CppNonExplicitConvertingConstructor
    Parameter(std::string name, bool value);

    [[nodiscard]] std::string Name() const;

    [[nodiscard]] kParameterType Type() const;

    [[nodiscard]] int Int() const;

    [[nodiscard]] float Float() const;

    [[nodiscard]] bool Bool() const;

    template <typename T> requires std::is_same_v<int, T>
    T Value() const
    {
        return static_cast<T>(Int());
    }

    template <typename T> requires std::is_same_v<float, T>
    T Value() const
    {
        return static_cast<T>(Float());
    }

    template <typename T> requires std::is_same_v<bool, T>
    T Value() const
    {
        return static_cast<T>(Bool());
    }

    template <typename T>
    void Set(const T next_value)
    {
        switch (m_type_)
        {
        case kParameterType::kInt: {
            m_value_.m_int_ = static_cast<int>(next_value);
            return;
        }
        case kParameterType::kFloat: {
            m_value_.m_float_ = static_cast<float>(next_value);
            return;
        }
        case kParameterType::kBool: {
            m_value_.m_bool_ = static_cast<bool>(next_value);
            return;
        }
        }

        assert(false && "Invalid parameter type");
    }

    // Convenience methods that use the template internally
    void SetInt(int next_value);

    void SetFloat(float next_value);

    void SetBool(bool next_value);
};
}