#include "Config.hpp"

#include <string>
#include <variant>

Config::Config(const std::map<std::string, std::string>& config)
    : m_Settings{config}
{
}
