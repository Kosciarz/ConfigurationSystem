#pragma once

#include <map>
#include <string>
#include <variant>

class Config
{
public:
    using Setting = std::variant<int, double, std::string>;

    Config() = default;

    Config(const std::map<std::string, Setting>& config);

    inline void SetSetting(const std::string& name, const Setting& value)
    {
        m_Settings[name] = value;
    }

    Setting GetValue(const std::string& name) const;

    std::string GetValueString(const std::string& name) const;

    inline std::map<std::string, Setting> Data() const { return m_Settings; }

private:
    std::map<std::string, Setting> m_Settings;
};
