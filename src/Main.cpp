#include "Config.hpp"
#include "ConfigSerializer.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> ParseArguments(const std::size_t argc, char** argv)
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
        std::cout << setting << ": " << value << '\n';
}

int main(int argc, char* argv[])
{
    std::vector<std::string> args = ParseArguments(argc, argv);
    const std::filesystem::path inputFile = args[0];
    const std::filesystem::path outputFile = args[1];

    try
    {
        auto config = Serialization::DeserializePlainText(inputFile);

        PrintConfig(config.Data());

        Serialization::SerializeJSON(outputFile, config); 
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}