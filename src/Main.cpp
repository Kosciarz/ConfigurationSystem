#include "Config.hpp"
#include "ConfigSerializer.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> ParseArguments(const std::size_t argc, char* argv[])
{
    std::vector<std::string> args{};
    args.reserve(argc - 1);
    for (std::size_t i{1}; i < argc; ++i)
        args.emplace_back(argv[i]);
    return args;
}

template <typename Key, typename Value>
void PrintConfig(const std::map<Key, Value>& map)
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

int main(int argc, char* argv[])
{
    std::vector<std::string> args = ParseArguments(argc, argv);

    try
    {
        auto config = Serialization::DeserializePlainText(args[0]);

        config.SetSetting("Name", "Example");
        config.SetSetting("Health", 100);
        config.SetSetting("Damage", 20);

        auto name = config.GetValue("Name");
        auto health = config.GetValue("Health");
        auto damage = config.GetValue("Damage");

        Serialization::SerializePlainText(args[0], config);

        PrintConfig(config.Data());
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}