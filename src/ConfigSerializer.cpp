#include "nlohmann/json.hpp"

#include "ConfigSerializer.hpp"

#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <variant>

static bool IsInteger(const std::string& str)
{
    for (const auto& ch : str)
        if (!std::isdigit(ch))
            return false;
    return true;
}

void Serialization::SerializePlainText(const std::filesystem::path& path, const Config& cfg)
{
    std::ofstream file(path);
    if (!file)
        std::cerr << "Exception opening file: " + path.string();

    for (const auto& [key, value] : cfg.Data())
    {
        std::visit([&](const auto& arg)
            {
                file << key << ": " << arg << '\n';
            },
            value);
    }
}

Config Serialization::DeserializePlainText(const std::filesystem::path& path)
{
    std::ifstream file(path);
    if (!file)
        std::cerr << "Exception opening file: " + path.string();

    std::map<std::string, Config::Setting> config{};
    std::string file_line{};

    while (std::getline(file, file_line))
    {
        auto position = std::distance(file_line.begin(), std::ranges::find(file_line, ':'));
        const std::string name = file_line.substr(0, position);
        const std::string value = file_line.substr(position + 2, file_line.size());

        std::size_t offset = 0;
        if (value.find('.') != std::string::npos)
            config[name] = std::stod(value, &offset);
        else if (IsInteger(value))
            config[name] = std::stoi(value);
        else
            config[name] = value;
    }
    return Config{config};
}

void Serialization::SerializeJSON(const std::filesystem::path& path, const Config& cfg)
{
}

Config Serialization::DeserializeJSON(const std::filesystem::path& path)
{
    return Config();
}

void Serialization::SerializeXML(const std::filesystem::path& path, const Config& cfg)
{
}

Config Serialization::DeserializeXML(const std::filesystem::path& path)
{
    return Config();
}

void Serialization::SerializeBinary(const std::filesystem::path& path, const Config& cfg)
{
}

Config Serialization::DeserializeBinary(const std::filesystem::path& path)
{
    return Config();
}

void Serialization::SerializeYAML(const std::filesystem::path& path)
{
}

Config Serialization::DeserializeYAML(const std::filesystem::path& path)
{
    return Config();
}
