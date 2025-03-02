#include "Config.hpp"
#include "ConfigSerializer.hpp"

#include <iostream>
#include <unordered_map>

template <typename Key, typename Value>
void PrintVariant(const std::unordered_map<Key, Value>& map)
{
    for (const auto& [setting, value] : map)
    {
        std::cout << setting << ": ";
        std::visit(
            [&](const auto& val)
            {
                using T = std::decay_t<decltype(val)>;
                if constexpr (!std::is_same_v<T, std::monostate>)
                {
                    std::cout << val << '\n';
                }
            },
            value);
    }
}

int main()
{

    try
    {
        auto config = Serialization::DeserializePlainText("../config-example.txt");

        config.SetSetting("Name", "Example");
        config.SetSetting("Health", 100);
        config.SetSetting("Damage", 20);

        auto name = config.GetValue("Name");
        auto health = config.GetValue("Health");
        auto damage = config.GetValue("Damage");

        Serialization::SerializePlainText("../config-example.txt", config);

        PrintVariant(config.Data());
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}