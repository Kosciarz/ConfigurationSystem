#pragma once

#include "Config.hpp"

#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include <variant>


namespace Serialization
{

void SerializePlainText(const std::filesystem::path& path, const Config& config);

Config DeserializePlainText(const std::filesystem::path& path);

void SerializeJSON(const std::filesystem::path& path, const Config& config);

Config DeserializeJSON(const std::filesystem::path& path);

void SerializeXML(const std::filesystem::path& path, const Config& config);

Config DeserializeXML(const std::filesystem::path& path);

void SerializeBinary(const std::filesystem::path& path, const Config& config);

Config DeserializeBinary(const std::filesystem::path& path);

void SerializeYAML(const std::filesystem::path& path);

Config DeserializeYAML(const std::filesystem::path& path);

} // namespace Serialization
