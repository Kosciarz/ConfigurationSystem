#include "Config.hpp"

#include <string>
#include <variant>

Config::Config(const std::map<std::string, std::string>& config)
    : m_Settings{config}
{
}

void Config::SetSetting(const std::string& setting, auto&& value)
{
    std::ostringstream oss;
    oss << value;
    m_Settings[setting] = value;
}

template<typename T>
std::string Config::GetValue(const std::string& setting) const
{
    auto it = m_Settings.find(setting);
    if (it == m_Settings.end())
        throw std::runtime_error{"Key not found: " + setting};

    std::istringstream iss{it->second};
    T value;
    if (!(iss >> value))
        throw std::runtime_error{"Failed to convert value: " + it->second};
    
    return value;
}
