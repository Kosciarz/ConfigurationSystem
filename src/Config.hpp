#pragma once

#include <map>
#include <string>
#include <variant>

class Config
{
public:
    using Settings = std::map<std::string, std::string>;

    Config() = default;

    explicit Config(const std::map<std::string, std::string>& config);

    inline void SetSetting(const std::string& name, const std::string& value)
    {
        m_Settings[name] = value;
    }

    std::string GetValue(const std::string& name) const
    {
        return m_Settings.at(name);
    }

    inline std::map<std::string, std::string> Data() const { return m_Settings; }

private:
    Settings m_Settings;
};
