#include "Config.hpp"

#include <string>
#include <variant>

Config::Config()
    : m_settings{}
{
}

Config::Config(std::map<std::string, Setting> config)
    : m_settings{config}
{
}

void Config::SetSetting(std::string_view name, const Config::Setting& value)
{
    m_settings[std::string{name}] = value;
}

Config::Setting Config::GetValue(std::string_view name) const
{
    return std::visit(
        [](auto&& value)
        {
            return Config::Setting{value};
        },
        m_settings.at(std::string{name}));
}
