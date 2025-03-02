#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <unordered_map>
#include <variant>

class Config
{
public:
    using Setting = std::variant<std::monostate, int, double, std::string>;

    Config();

    Config(std::unordered_map<std::string, Setting>);

    void SetSetting(const std::string& name, const Setting& value);

    Setting GetValue(const std::string& name) const;

    std::unordered_map<std::string, Setting> Data() const { return m_settings; }

private:
    std::unordered_map<std::string, Setting> m_settings;
};

#endif // CONFIG_HPP