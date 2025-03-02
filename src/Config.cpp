#include "Config.hpp"

#include <variant>

Config::Config()
    : m_settings{}
{
}

Config::Config(std::unordered_map<std::string, Setting> config)
    : m_settings{config}
{
}

void Config::SetSetting(const std::string& name, const Config::Setting& value)
{
    m_settings[name] = value;
}

Config::Setting Config::GetValue(const std::string& name) const
{
    auto setting = m_settings.at(name);

    return std::visit(
        [](auto&& value)
        {
            return Config::Setting{value};
        },
        setting);
}
