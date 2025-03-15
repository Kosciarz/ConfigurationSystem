#include <nlohmann/json.hpp>

#include "ConfigSerializer.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using json = nlohmann::json;

void Serialization::SerializePlainText(const std::filesystem::path& path, const Config& config)
{
    std::ofstream file(path);
    if (!file)
        std::cerr << "Exception opening file: " + path.string();

    for (const auto& [setting, value] : config.Data())
        file << setting << ": " << value << '\n';
}

Config Serialization::DeserializePlainText(const std::filesystem::path& path)
{
    std::ifstream file(path);
    if (!file)
        std::cerr << "Exception opening file: " + path.string();

    Config::Settings newConfig{};
    std::string file_line{};

    while (std::getline(file, file_line))
    {
        auto delimPosition = std::distance(file_line.begin(), std::ranges::find(file_line, ':'));
        const std::string name = file_line.substr(0, delimPosition);
        const std::string value = file_line.substr(delimPosition + 2, file_line.size());

        newConfig[name] = value;
    }
    return Config{newConfig};
}

void Serialization::SerializeJSON(const std::filesystem::path& path, const Config& config)
{
    std::ofstream file(path);
    if (!file)
        std::cerr << "Exception opening file: " + path.string();
    
    json configJson{};

    for (const auto& [setting, value] : config.Data())
        configJson[setting] = value;
    
    file << configJson.dump(4);
}

Config Serialization::DeserializeJSON(const std::filesystem::path& path)
{
    std::ifstream file(path);
    if (!file)
        std::cerr << "Exception opening file: " + path.string();

    Config::Settings newConfig{};
    
    json configJson{};
    file >> configJson;

    for (const auto& [setting, value] : configJson.items())
        configJson[setting] = value;

    return Config{newConfig};
}

void Serialization::SerializeXML(const std::filesystem::path& path, const Config& config)
{
}

Config Serialization::DeserializeXML(const std::filesystem::path& path)
{
    return Config();
}

void Serialization::SerializeBinary(const std::filesystem::path& path, const Config& config)
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
