#include "parameter.h"

namespace state_machine
{
Parameter::Parameter(std::string name, const int value): m_name_(std::move(name)), m_type_(kParameterType::kInt)
{
    m_value_.m_int_ = value;
}

Parameter::Parameter(std::string name, const float value): m_name_(std::move(name)), m_type_(kParameterType::kFloat)
{
    m_value_.m_float_ = value;
}

Parameter::Parameter(std::string name, const bool value): m_name_(std::move(name)), m_type_(kParameterType::kBool)
{
    m_value_.m_bool_ = value;
}

std::string Parameter::Name() const
{
    return m_name_;
}

kParameterType Parameter::Type() const
{
    return m_type_;
}

int Parameter::Int() const
{
    switch (m_type_)
    {
    case kParameterType::kInt: {
        return m_value_.m_int_;
    }
    case kParameterType::kFloat: {
        return static_cast<int>(m_value_.m_float_);
    }
    case kParameterType::kBool: {
        return m_value_.m_bool_;
    }
    }

    assert(false && "Invalid parameter type");
    return 0;
}

float Parameter::Float() const
{
    switch (m_type_)
    {
    case kParameterType::kInt: {
        return static_cast<float>(m_value_.m_int_);
    }
    case kParameterType::kFloat: {
        return m_value_.m_float_;
    }
    case kParameterType::kBool: {
        return m_value_.m_bool_;
    }
    }

    assert(false && "Invalid parameter type");
    return 0.0f;
}

bool Parameter::Bool() const
{
    switch (m_type_)
    {
    case kParameterType::kInt: {
        return m_value_.m_int_ != 0;
    }
    case kParameterType::kFloat: {
        return m_value_.m_float_ != 0.0f;
    }
    case kParameterType::kBool: {
        return m_value_.m_bool_;
    }
    }

    assert(false && "Invalid parameter type");
    return false;
}

void Parameter::SetInt(const int next_value)
{
    Set(next_value);
}

void Parameter::SetFloat(const float next_value)
{
    Set(next_value);
}

void Parameter::SetBool(const bool next_value)
{
    Set(next_value);
}
}