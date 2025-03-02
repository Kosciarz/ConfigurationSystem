#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <map>
#include <variant>
#include <string_view>

class Config
{
public:
    using Setting = std::variant<std::monostate, int, double, std::string>;

    Config();

    Config(std::map<std::string, Setting>);

    void SetSetting(std::string_view name, const Setting& value);

    Setting GetValue(std::string_view name) const;

    std::string GetValueString(std::string_view name) const;

    std::map<std::string, Setting> Data() const { return m_settings; }

private:
    std::map<std::string, Setting> m_settings;
};

#endif // CONFIG_HPP