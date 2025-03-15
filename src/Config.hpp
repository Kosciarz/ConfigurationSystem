#pragma once

#include <map>
#include <string>
#include <variant>
#include <sstream>

class Config
{
public:
    using Settings = std::map<std::string, std::string>;

    Config() = default;

    explicit Config(const std::map<std::string, std::string>& config);

    void SetSetting(const std::string& setting, auto&& value);

    template <typename T>
    std::string GetValue(const std::string& setting) const;

    inline std::map<std::string, std::string> Data() const { return m_Settings; }

private:
    Settings m_Settings;
};
