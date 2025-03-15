#include "Config.hpp"
#include "ConfigSerializer.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> ParseArguments(const int argc, char** argv)
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
        std::visit([&](const auto& val)
            {
                std::cout << setting << ": " << val << '\n';
            },
            value);
    }
}

int main(int argc, char* argv[])
{
    std::vector<std::string> args = ParseArguments(argc, argv);
    const std::filesystem::path filePath = args[0];

    try
    {
        auto config = Serialization::DeserializePlainText(filePath);

        PrintConfig(config.Data());
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}