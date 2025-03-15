#include "Config.hpp"

#include <string>
#include <variant>

Config::Config(const std::map<std::string, Setting>& config)
    : m_Settings{config}
{
}

Config::Setting Config::GetValue(const std::string& name) const
{
    return std::visit([](auto&& value)
        {
            return Config::Setting{value};
        },
        m_Settings.at(name));
}
